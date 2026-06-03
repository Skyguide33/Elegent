/**
 * Problem Analysis:
 * We are given a rooted tree where each node i has a color range [l_i, r_i].
 * A node's color c_i is chosen uniformly at random from [l_i, r_i].
 * We need to compute the expected value and variance of the "chromaticity" of a subtree.
 * Chromaticity is defined as the number of maximal connected components of the same color.
 * 
 * Let S_u be the set of nodes in the subtree of u.
 * The number of monochromatic components C = |S_u| - Y, where Y is the number of monochromatic edges.
 * Y = sum_{e in E(S_u)} I(e is mono).
 * 
 * E[C] = |S_u| - E[Y].
 * E[Y] = sum_{(u, v) in E(S_u)} P(c_u = c_v).
 * 
 * Var(C) = Var(Y) = E[Y^2] - E[Y]^2.
 * Var(Y) = sum_{e} (P(e) - P(e)^2) + sum_{e != f} (P(e and f) - P(e)P(f)).
 * 
 * The sums involve single edges and pairs of edges.
 * In a rooted tree, edges in S_u are of the form (p_v, v) for v in S_u \ {u}.
 * Adjacent edge pairs (e, f) in the subtree can be:
 * 1. Sibling edges: (u, v) and (u, w).
 * 2. Parent-Child edges: (p_v, v) and (v, w).
 * 
 * We maintain terms in a Fenwick Tree (BIT) mapped by DFS order to support subtree queries.
 * Since the tree is randomly generated (Random Recursive Tree), the maximum degree is small (logarithmic) on average.
 * This allows us to iterate over children and pairs of children for updates.
 * 
 * Terms associated with node v (representing edge (p_v, v)):
 * - Prob(v): P(c_v = c_{p_v}).
 * - Val1(v): Prob(v) - Prob(v)^2.
 * - PC(v): sum_{y in children(v)} (P(p_v, v, y) - P(p_v, v)P(v, y)). Represents interaction between (p_v, v) and (v, y).
 * - Sib(v): sum_{y1 != y2 in children(v)} (P(v, y1, y2) - P(v, y1)P(v, y2)). Represents interaction between (v, y1) and (v, y2).
 * 
 * Global query for u:
 * E[C] = Size(u) - (QueryExp(u) - Prob(u)).
 * Var(C) = (QueryVar(u) - (Val1(u) + 2*PC(u))).
 * Note: QueryVar sums (Val1 + 2*PC + 2*Sib). We subtract u's parent-related terms because edge (p_u, u) is not in S_u.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Constants
const int MOD = 998244353;
const int MAXN = 500005;

// Modular Arithmetic
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

// Global Variables
int n, q;
int p[MAXN]; // parent
vector<int> adj[MAXN];
int l[MAXN], r[MAXN];
long long len[MAXN], invLen[MAXN];

// DFS Order for BIT
int dfn[MAXN], sz[MAXN], timer;
int node_map[MAXN]; // dfn to node index if needed

// Stored computed values to avoid re-computation during `remove` phase
// However, since we just update, we can recompute. 
// Storing interactions might be memory heavy, but storing node-level aggregates is fine.
long long val1[MAXN];
long long val_pc[MAXN];
long long val_sib[MAXN];
long long val_prob[MAXN];

// Fenwick Tree
long long bit_exp[MAXN]; // Stores Prob(v)
long long bit_var[MAXN]; // Stores Val1(v) + 2*PC(v) + 2*Sib(v)

void bit_add(long long* bit, int idx, long long val) {
    val %= MOD;
    if (val < 0) val += MOD;
    for (; idx <= n; idx += idx & -idx) {
        bit[idx] = (bit[idx] + val) % MOD;
    }
}

long long bit_query(long long* bit, int idx) {
    long long res = 0;
    for (; idx > 0; idx -= idx & -idx) {
        res = (res + bit[idx]) % MOD;
    }
    return res;
}

long long bit_query_range(long long* bit, int L, int R) {
    if (L > R) return 0;
    long long res = bit_query(bit, R) - bit_query(bit, L - 1);
    return (res % MOD + MOD) % MOD;
}

// Helpers for Probabilities
void update_len(int u) {
    len[u] = r[u] - l[u] + 1;
    invLen[u] = modInverse(len[u]);
}

long long get_intersect(int u, int v) {
    int L = max(l[u], l[v]);
    int R = min(r[u], r[v]);
    if (L > R) return 0;
    return (long long)(R - L + 1);
}

long long get_intersect3(int u, int v, int w) {
    int L = max({l[u], l[v], l[w]});
    int R = min({r[u], r[v], r[w]});
    if (L > R) return 0;
    return (long long)(R - L + 1);
}

long long prob2(int u, int v) {
    long long num = get_intersect(u, v);
    if (num == 0) return 0;
    return num * invLen[u] % MOD * invLen[v] % MOD;
}

long long prob3(int u, int v, int w) {
    long long num = get_intersect3(u, v, w);
    if (num == 0) return 0;
    return num * invLen[u] % MOD * invLen[v] % MOD * invLen[w] % MOD;
}

// DFS initialization
void dfs(int u) {
    dfn[u] = ++timer;
    sz[u] = 1;
    for (int v : adj[u]) {
        dfs(v);
        sz[u] += sz[v];
    }
}

// Calculation Helpers
// Calculate Val1(u) = P(u, p) - P(u, p)^2
long long calc_val1(int u) {
    if (u == 1) return 0; // Root has no parent edge
    int par = p[u];
    long long P = prob2(u, par);
    val_prob[u] = P;
    long long res = (P - P * P) % MOD;
    if (res < 0) res += MOD;
    return res;
}

// Calculate PC(u) = sum_{y in children} (P(p, u, y) - P(p, u)P(u, y))
long long calc_pc(int u) {
    if (u == 1) return 0;
    int par = p[u];
    long long res = 0;
    long long P_par_u = prob2(par, u);
    
    for (int y : adj[u]) {
        long long term = prob3(par, u, y) - P_par_u * prob2(u, y) % MOD;
        res = (res + term) % MOD;
    }
    if (res < 0) res += MOD;
    return res;
}

// Calculate Sib(u) = sum_{y1 < y2} 2 * (P(u, y1, y2) - P(u, y1)P(u, y2))
long long calc_sib(int u) {
    long long res = 0;
    // Iterate all pairs. Random Recursive Tree -> Degree is small.
    int deg = adj[u].size();
    for (int i = 0; i < deg; ++i) {
        int y1 = adj[u][i];
        long long P1 = prob2(u, y1);
        for (int j = i + 1; j < deg; ++j) {
            int y2 = adj[u][j];
            long long P2 = prob2(u, y2);
            long long P12 = prob3(u, y1, y2);
            long long term = (P12 - P1 * P2) % MOD;
            res = (res + term) % MOD;
        }
    }
    // Multiply by 2 because formula is sum over y1 != y2
    res = (res * 2) % MOD;
    if (res < 0) res += MOD;
    return res;
}

// Update logic
// Update node u affects:
// 1. u itself: val1, PC, Sib
// 2. Parent p[u]: PC (term involving u), Sib (term involving u)
// 3. Children y of u: val1 (depends on u), PC (depends on u)
// We assume degree is small enough to iterate.

void apply_update(int u) {
    // 1. Update u's internal values
    long long old_val1 = val1[u];
    long long old_pc = val_pc[u];
    long long old_sib = val_sib[u];
    long long old_prob = val_prob[u];
    
    val1[u] = calc_val1(u);
    val_pc[u] = calc_pc(u);
    val_sib[u] = calc_sib(u);
    
    long long diff_var = (val1[u] + 2 * val_pc[u] + 2 * val_sib[u]) - (old_val1 + 2 * old_pc + 2 * old_sib);
    long long diff_exp = val_prob[u] - old_prob;
    
    bit_add(bit_var, dfn[u], diff_var);
    bit_add(bit_exp, dfn[u], diff_exp);
    
    // 2. Update Parent p[u]
    if (u != 1) {
        int par = p[u];
        // PC(par): only term involving child u changes.
        // Term u: P(grandp, par, u) - P(grandp, par)P(par, u)
        // Wait, par's PC depends on par's parent.
        // u changes -> P(par, u) changes. P(grandp, par, u) changes.
        // We need to update par's PC sum.
        // Since we don't store individual terms, we can recompute PC(par) completely 
        // OR compute delta. Since deg is small, recomputing is safer/easier.
        // BUT par didn't change range. Only u changed.
        // Recomputing PC(par) involves iterating all children of par.
        
        long long old_pc_par = val_pc[par];
        val_pc[par] = calc_pc(par);
        long long diff_pc_par = val_pc[par] - old_pc_par;
        bit_add(bit_var, dfn[par], 2 * diff_pc_par);
        
        // Sib(par): terms involving u and sibling s.
        long long old_sib_par = val_sib[par];
        val_sib[par] = calc_sib(par);
        long long diff_sib_par = val_sib[par] - old_sib_par;
        bit_add(bit_var, dfn[par], 2 * diff_sib_par);
    }
    
    // 3. Update Children y of u
    for (int y : adj[u]) {
        // Val1(y): depends on P(y, u).
        long long old_val1_y = val1[y];
        long long old_prob_y = val_prob[y];
        
        val1[y] = calc_val1(y);
        
        long long diff_val1_y = val1[y] - old_val1_y;
        long long diff_prob_y = val_prob[y] - old_prob_y;
        
        bit_add(bit_var, dfn[y], diff_val1_y);
        bit_add(bit_exp, dfn[y], diff_prob_y);
        
        // PC(y): depends on P(u, y, z) and P(u, y).
        long long old_pc_y = val_pc[y];
        val_pc[y] = calc_pc(y);
        long long diff_pc_y = val_pc[y] - old_pc_y;
        
        bit_add(bit_var, dfn[y], 2 * diff_pc_y);
    }
}


void solve() {
    if (!(cin >> n >> q)) return;
    
    // Reset
    for (int i = 1; i <= n; ++i) adj[i].clear();
    timer = 0;
    
    // Input
    for (int i = 2; i <= n; ++i) {
        cin >> p[i];
        adj[p[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i) cin >> l[i];
    for (int i = 1; i <= n; ++i) cin >> r[i];
    
    // Precompute
    for (int i = 1; i <= n; ++i) update_len(i);
    dfs(1);
    
    // Clear BIT
    for (int i = 0; i <= n; ++i) {
        bit_exp[i] = 0;
        bit_var[i] = 0;
    }
    
    // Initial Calculation
    // Order matters? Values depend on neighbors.
    // Compute independent values first.
    for (int i = 1; i <= n; ++i) {
        val1[i] = calc_val1(i);
        val_pc[i] = calc_pc(i);
        val_sib[i] = calc_sib(i);
        
        long long term_var = (val1[i] + 2 * val_pc[i] + 2 * val_sib[i]) % MOD;
        long long term_exp = val_prob[i]; // set inside calc_val1
        
        bit_add(bit_var, dfn[i], term_var);
        bit_add(bit_exp, dfn[i], term_exp);
    }
    
    // Queries
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, new_l, new_r;
            cin >> u >> new_l >> new_r;
            // To update, we need to remove old contributions and add new ones.
            // However, dependencies are complex.
            // Simpler: 
            // 1. Identify affected nodes: u, p[u], children[u].
            // 2. Calculate 'before' values for these specific components.
            // 3. Update u's range.
            // 4. Calculate 'after' values.
            // 5. Apply delta to BIT.
            
            // Affected set logic needs to be precise to avoid double counting?
            // We can just update sequentially.
            // BUT, updating u affects p[u]. If we then update p[u] range... no only u's range changes.
            // The function apply_update handles the propagation of u's range change to neighbors.
            // But wait, apply_update assumes u's range ALREADY changed?
            // Or does it use old values?
            // My `apply_update` computes NEW values based on current global l/r arrays.
            // It compares with stored `val1`, `val_pc` etc.
            // So step is:
            // 1. Update l[u], r[u], len[u], invLen[u].
            // 2. Call apply_update(u).
            
            // Warning: apply_update(u) recalculates p[u]'s values.
            // Does p[u] calculation use the OLD val1[u]? No, val1 is local to node.
            // p[u] calculation uses prob2(p[u], u). This uses current l[u]. Correct.
            
            l[u] = new_l;
            r[u] = new_r;
            update_len(u);
            apply_update(u);
            
        } else {
            int u;
            cin >> u;
            
            // Expectation
            long long sum_probs = bit_query_range(bit_exp, dfn[u], dfn[u] + sz[u] - 1);
            // We want sum over S_u \ {u}. Total sum includes u (which is P(u, p[u])).
            // P(u, p[u]) is exactly what we stored at u.
            long long sum_probs_sub = (sum_probs - val_prob[u] + MOD) % MOD;
            long long ans_exp = (sz[u] - sum_probs_sub + MOD) % MOD;
            
            // Variance
            long long sum_var_terms = bit_query_range(bit_var, dfn[u], dfn[u] + sz[u] - 1);
            // We want sum over S_u \ {u} of (Val1 + 2PC) + sum over S_u of (2Sib).
            // BIT stores (Val1 + 2PC + 2Sib) at each node.
            // For u, BIT has (Val1(u) + 2PC(u) + 2Sib(u)).
            // We want to exclude Val1(u) and 2PC(u) because they involve edge/interaction with parent p[u].
            // We keep 2Sib(u).
            long long subtract = (val1[u] + 2 * val_pc[u]) % MOD;
            long long ans_var = (sum_var_terms - subtract + MOD) % MOD;
            
            cout << ans_exp << " " << ans_var << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}