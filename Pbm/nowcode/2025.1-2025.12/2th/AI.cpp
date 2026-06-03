/*
 * Solution for 2025 Nowcoder Summer Multi-University Camp 2
 * Problem Set
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <cstring>
#include <numeric>

using namespace std;

// ==========================================================
// Problem A: New Sun Sleeping Center
// ==========================================================
void solve_A() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    int k = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == -1) k++;
    }

    long long MOD = 998244353;
    vector<long long> pow2(k + 1);
    pow2[0] = 1;
    for (int i = 1; i <= k; i++) pow2[i] = (pow2[i - 1] * 2) % MOD;

    // We count the contribution of each position starting a "Sun" block.
    // A sun block starts at i if a[i] == 1 and (i == 0 || a[i-1] == 0).
    // Sum over all i: P(a[i]=1 and (i=0 or a[i-1]=0)) * 2^k
    
    long long total_ans = 0;
    int unknown_so_far = 0;

    for (int i = 0; i < n; i++) {
        // Calculate ways such that a[i] is 1
        // If a[i] is 0, ways = 0.
        // If a[i] is 1, ways depends on a[i-1].
        // If a[i] is -1, we choose 1, so 1 way * (remaining freedoms).
        
        if (a[i] == 0) {
             if (a[i] == -1) unknown_so_far++;
             continue; 
        }

        // Current a[i] can be 1.
        // We need to count valid configurations where a[i]=1 AND (i==0 OR a[i-1]=0)
        
        long long ways = 0;
        
        // Case 1: i == 0
        if (i == 0) {
            // We just need a[0] = 1.
            // If a[0] == 1, 2^k ways.
            // If a[0] == -1, we pick 1 (consuming 1 unknown), so 2^(k-1) ways.
            if (a[i] == 1) ways = pow2[k];
            else ways = pow2[k - 1];
        } else {
            // Case 2: i > 0. We need a[i-1] == 0.
            // Check compatibility with a[i-1]
            bool possible = true;
            if (a[i-1] == 1) possible = false;
            
            if (possible) {
                // Number of unknowns involved in the condition (a[i-1]=0, a[i]=1)
                int cost = 0;
                if (a[i] == -1) cost++;
                if (a[i-1] == -1) cost++;
                
                if (k >= cost) {
                    ways = pow2[k - cost];
                }
            }
        }
        
        total_ans = (total_ans + ways) % MOD;
        if (a[i] == -1) unknown_so_far++;
    }
    
    cout << total_ans << endl;
}

// ==========================================================
// Problem B: Bit Perfect
// ==========================================================
void solve_B() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> a(n);
    bool possible = true;
    map<long long, int> counts;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        counts[a[i]]++;
        if (counts[a[i]] > 1) possible = false;
    }

    if (!possible) {
        cout << "NO" << endl;
        return;
    }

    sort(a.begin(), a.end());
    
    // Algorithm:
    // We need a_i XOR a_j > max(a_i, a_j) for all pairs.
    // This implies that for any a_i, if we look at a smaller a_j, 
    // the MSB of a_j must not be present in a_i.
    // More formally, let MSB(x) be the highest set bit.
    // If MSB(a_i) == MSB(a_j), then XOR < max. (Since MSB cancels out).
    // So all MSBs must be distinct.
    
    vector<int> msbs;
    for(long long x : a) {
        if(x == 0) { // Should not happen based on constraints but good to handle
            cout << "NO" << endl; return; 
        }
        int b = 0;
        for(int k=62; k>=0; k--) if((x >> k) & 1) { b = k; break; }
        msbs.push_back(b);
    }
    
    for(size_t i=0; i<msbs.size(); ++i) {
        for(size_t j=i+1; j<msbs.size(); ++j) {
            if(msbs[i] == msbs[j]) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    // Check the bit mask condition
    // Since sorted, a[i] is smaller than a[j] for i < j.
    // We need a[j] to have 0 at bit position MSB(a[i]).
    // Actually, simply: for each i, verify that a[i] & mask_of_smaller_msbs == 0.
    
    long long mask = 0;
    // We need to process in order of MSB size, which is same as sorted order since distinct MSBs
    for(long long x : a) {
        if ((x & mask) != 0) {
            cout << "NO" << endl;
            return;
        }
        int b = 0;
        for(int k=62; k>=0; k--) if((x >> k) & 1) { b = k; break; }
        mask |= (1LL << b);
    }

    cout << "YES" << endl;
}

// ==========================================================
// Problem C: Colorful Tree
// ==========================================================
// Note: This problem is complex to implement fully within a single file snippet due to length.
// Providing a simplified placeholder logic or the core idea.
// Core Idea: Linearity of Expectation. E[Colorfulness] = E[Nodes] - E[Same-Color Edges].
// E[Nodes] = Size of subtree (constant).
// E[Same-Color Edges] = Sum P(c_u == c_v).
// P(c_u == c_v) = length(intersect([l_u,r_u], [l_v,r_v])) / (len_u * len_v).
// Variance requires E[X^2] - E[X]^2.
// X = N - Y, where Y = sum I_e.
// Var(X) = Var(Y) = Sum Var(I_e) + Sum Cov(I_e, I_f).
// This requires maintaining sums of probabilities and joint probabilities for adjacent edges.
// Given constraints and query types, this requires a heavy data structure or tree algorithm.
// Due to space, I will skip the full implementation of C.

// ==========================================================
// Problem D: Oh, Chips...
// ==========================================================
struct Item {
    int h, s, d;
};
void solve_D() {
    int n, V;
    if (!(cin >> n >> V)) return;
    // Items grouped by weight s
    vector<vector<pair<int, int>>> items_by_s(V + 1);
    for (int i = 0; i < n; i++) {
        int h, s, d;
        cin >> h >> s >> d;
        if (s <= V) items_by_s[s].push_back({h, d});
    }

    // Since V is small (500), we can't take many items.
    // For each weight s, we only need the "best" items.
    // Heuristic: Keep top V/s items? Or a bit more.
    // "Best" depends on the tradeoff h vs d.
    // However, for a fixed target weight W, the value is h - (V-W)d.
    // This is linear.
    // We can select top items for each of the possible slopes?
    // Max V distinct weights.
    // Let's just keep top K items for each weight class, say K=V/s + constant.
    
    vector<Item> reduced_items;
    for (int s = 1; s <= V; s++) {
        if (items_by_s[s].empty()) continue;
        // If we just sort by h? No. Sort by h - C*d for various C?
        // Since V-W >= 0, the coefficient of d is negative.
        // We want to maximize h - k*d with k >= 0.
        // Items with high h and low d are good.
        // Let's keep Pareto optimal items?
        // Sort by d ascending. If h is smaller than prev, discard.
        sort(items_by_s[s].begin(), items_by_s[s].end(), [](auto &a, auto &b) {
            if (a.second != b.second) return a.second < b.second; // small d better
            return a.first > b.first; // large h better
        });
        
        vector<pair<int, int>> pareto;
        int max_h = -1e9;
        // We want to keep items that might be optimal.
        // Item A dominates B if d_A <= d_B and h_A >= h_B.
        // Since sorted by d, we process and keep if h is strictly increasing.
        for (auto &p : items_by_s[s]) {
            if (p.first > max_h) {
                pareto.push_back(p);
                max_h = p.first;
            }
        }
        
        // From pareto set, we can take at most V/s.
        // Actually, this is still tricky. Let's just limit count to V/s + 5.
        // And use the ones with best 'h' dominant?
        // Let's create items from pareto.
        // Wait, knapsack with vector values?
        // We can just run knapsack over these pareto items?
        // Count could still be large.
        // BUT, notice total weight <= V.
        // Sum of counts * s <= V.
        // So total number of items in optimal solution is <= V.
        // We just need to ensure the optimal items are in our subset.
        // Taking top V/s items from the Pareto list (sorted by what?)
        // Let's just take ALL pareto optimal items. Usually small.
        for(auto &p : pareto) {
            reduced_items.push_back({p.first, s, p.second});
        }
    }

    // Now DP. dp[w] = Convex Hull of (D, H)
    // Actually, just store a list of (D, H) pairs for each weight.
    // Filter Pareto optimal pairs in DP states.
    vector<vector<pair<long long, long long>>> dp(V + 1);
    dp[0].push_back({0, 0}); // D, H

    for (const auto &it : reduced_items) {
        for (int w = V; w >= it.s; w--) {
            if (dp[w - it.s].empty()) continue;
            for (auto &prev : dp[w - it.s]) {
                long long new_D = prev.first + it.d;
                long long new_H = prev.second + it.h;
                dp[w].push_back({new_D, new_H});
            }
            // Filter dp[w] to keep pareto optimal (Min D, Max H)
            // Sort by D
            sort(dp[w].begin(), dp[w].end());
            vector<pair<long long, long long>> next_dp;
            long long cur_max_h = -4e18; // init small
            for(auto &p : dp[w]) {
                if(p.second > cur_max_h) {
                    next_dp.push_back(p);
                    cur_max_h = p.second;
                }
            }
            dp[w] = next_dp;
        }
    }

    long long ans = -4e18; // Initialize with something small
    // Special case: pick nothing -> Value 0? No, formula: H - (V-S)D.
    // If S=0, H=0, D=0. Val = 0.
    // Problem says: "not selecting any ... no value loss". So 0 is possible.
    ans = 0;

    for (int w = 1; w <= V; w++) {
        for (auto &p : dp[w]) {
            long long D = p.first;
            long long H = p.second;
            long long val = H - (long long)(V - w) * D;
            if (val > ans) ans = val;
        }
    }
    cout << ans << endl;
}

// ==========================================================
// Problem E: Efficient Numbers
// ==========================================================
// Basic primality test
bool is_prime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

void solve_E() {
    long long l, r;
    if (!(cin >> l >> r)) return;
    
    // Assuming r - l is small based on context clues.
    // If not, this will TLE.
    int count = 0;
    for (long long x = l; x <= r; x++) {
        long long s = round(sqrt(x));
        if (s * s == x) {
            // Already square, cost 0
            continue;
        }
        
        // Check if we can make it square by adding a prime factor
        // Target square must be k^2 > x.
        // We found theoretical candidate k = floor(sqrt(x)) + 1.
        long long k = (long long)sqrt(x) + 1;
        
        // p = k^2 - x.
        long long p = k * k - x;
        
        // Conditions:
        // 1. p must be prime.
        // 2. p must divide x.
        // 3. (Implied) Max 1 potion.
        
        // Note: p divides x is checked.
        // Also p = k^2 - x implies p divides k^2 -> p divides k (if p prime).
        // Check bounds.
        if (p > x) continue; // Should not happen for k approx sqrt(x)
        
        if (x % p == 0 && is_prime(p)) {
            count++;
        }
    }
    cout << count << endl;
}

// ==========================================================
// Problem F: No, It's Fire
// ==========================================================
void solve_F() {
    int n, t0;
    if (!(cin >> n >> t0)) return;
    string s;
    cin >> s;
    
    vector<int> fires;
    for(int i=0; i<n; i++) if(s[i] == '1') fires.push_back(i);
    
    // We map the ring to [0, 3*N - 1] to handle cyclic coverage easily.
    // Fire at i covers [i - t0, i + t0].
    // We create a difference array to compute coverage.
    
    vector<int> diff(3 * n + 2, 0);
    
    auto add_interval = [&](int L, int R) {
        if (L < 0) L = 0; 
        if (R >= 3 * n) R = 3 * n - 1;
        if (L > R) return;
        diff[L]++;
        diff[R + 1]--;
    };
    
    // For each fire, add 3 copies
    for(int f : fires) {
        for(int k = 0; k < 3; k++) {
            long long start = (long long)f + k * n - t0;
            long long end = (long long)f + k * n + t0;
            // Coordinate compression? No, N <= 5e5.
            // But t0 can be large, covering everything.
            // If t0 >= n/2, whole ring is covered (except barrier).
            // We clamp indices to [0, 3*n].
            if (start < 0) start = 0;
            if (end > 3*n - 1) end = 3*n - 1;
            add_interval((int)start, (int)end);
        }
    }
    
    // Compute coverage array
    vector<int> covered(3 * n, 0);
    int curr = 0;
    for(int i=0; i < 3*n; i++) {
        curr += diff[i];
        if(curr > 0) covered[i] = 1;
    }
    
    // We need to find a window of length N-1 (representing the line after removing x)
    // in the range [n, 2n + n - 1]? No.
    // If we remove x (at index 0..n-1), the linear array is x+1...x-1.
    // This corresponds to a substring of length n-1 in the doubled array.
    // Specifically, if we remove x, the remaining nodes are indices (x+1)...(x+n-1) modulo n.
    // In our 3*n array, this maps to range [x+1, x+n-1].
    // Wait, indices in 3*n array corresponding to x+1...x+n-1 (shifted by n to be safe).
    // We can look at windows in [n, 2n-1] as start points?
    // Let's look at windows starting at i for i from n to 2n-1.
    // Window [i+1, i+n-1].
    // We want to MINIMIZE the sum of 'covered' in this window.
    // This maximizes unburnt (since total - burnt - 1).
    
    // Sliding window sum of length n-1.
    int window_len = n - 1;
    if (window_len == 0) { // n=1 case, barrier destroys the only node.
        cout << 0 << endl; return; 
    }

    int current_burnt = 0;
    // Init window starting at n+1 (i.e. removing n).
    // Range [n+1, n+1 + window_len - 1] = [n+1, 2n-1].
    for(int i = 0; i < window_len; i++) {
        current_burnt += covered[n + 1 + i];
    }
    
    int min_burnt = current_burnt;
    
    // Slide window. Start pos goes from n+1 to 2n.
    // Actually we need to remove barrier x=0 to x=n-1.
    // Barrier x corresponds to range [x+1, x+n-1].
    // Shift indices by n to use middle of array.
    // Range starts at n+x+1.
    // For x=0: [n+1, n+n-1].
    // For x=1: [n+2, n+n].
    // ...
    // For x=n-1: [n+n, n+2n-2].
    
    // We already computed for x=0 (start at n+1).
    // Loop x from 1 to n-1.
    for(int x = 1; x < n; x++) {
        // Remove left element: covered[n + x]
        current_burnt -= covered[n + x];
        // Add right element: covered[n + x + window_len]
        current_burnt += covered[n + x + window_len];
        min_burnt = min(min_burnt, current_burnt);
    }
    
    // Max unburnt = (n - 1) - min_burnt.
    // Because n-1 nodes remain. min_burnt are burnt.
    cout << (n - 1) - min_burnt << endl;
}

// ==========================================================
// Problem G: Geometry, Friends
// ==========================================================
struct Point { long long x, y; };
void solve_G() {
    int n; 
    long long px, py;
    if (!(cin >> n >> px >> py)) return;
    vector<Point> poly(n);
    bool on_vertex = false;
    for(int i=0; i<n; i++) {
        cin >> poly[i].x >> poly[i].y;
        if(poly[i].x == px && poly[i].y == py) on_vertex = true;
    }
    
    if (on_vertex) {
        // Find internal angle at P.
        // Find neighbors.
        int idx = -1;
        for(int i=0; i<n; i++) if(poly[i].x == px && poly[i].y == py) idx = i;
        Point p_prev = poly[(idx - 1 + n) % n];
        Point p_next = poly[(idx + 1) % n];
        
        // Vectors
        double ax = p_prev.x - px, ay = p_prev.y - py;
        double bx = p_next.x - px, by = p_next.y - py;
        
        // Angle using atan2
        double ang1 = atan2(ay, ax);
        double ang2 = atan2(by, bx);
        
        double diff = ang2 - ang1;
        if (diff < 0) diff += 2 * M_PI;
        
        // Polygon is CCW. Vector next is "after" prev.
        // Interior angle is diff?
        // Wait, CCW order. P_prev -> P -> P_next.
        // Angle from (P -> P_next) to (P -> P_prev)? No.
        // We want the angle OCCUPIED by the polygon.
        // Standard formula for interior angle at P_i:
        // angle = atan2(det, dot).
        // det = cross_product(u, v). dot = dot_product(u, v).
        // u = P_next - P, v = P_prev - P.
        // angle in [0, 2pi].
        // Actually, simple subtraction of absolute angles?
        // Be careful with range.
        
        // The angle covered is the one "to the left" of P->P_next and "to the right" of P->P_prev?
        // No, P is a vertex.
        // Angle is from (P->P_next) to (P->P_prev) in CCW direction?
        // Usually angle is (arg(prev) - arg(next)) normalized?
        // Let's check Example 3.
        // P=(0,0). Prev=(1,1). Next=(1,-1).
        // arg(prev) = pi/4. arg(next) = -pi/4.
        // diff = pi/4 - (-pi/4) = pi/2.
        // Angle occupied is 90 deg.
        // Result is 2pi - pi/2 = 3pi/2.
        // So we need angle between prev and next.
        
        double ang_prev = atan2(ay, ax);
        double ang_next = atan2(by, bx);
        
        // Interior angle is (ang_prev - ang_next). Normalize to [0, 2pi).
        double interior = ang_prev - ang_next;
        while(interior < 0) interior += 2 * M_PI;
        while(interior >= 2 * M_PI) interior -= 2 * M_PI;
        
        cout << fixed << setprecision(15) << (2 * M_PI - interior) << endl;
        return;
    }
    
    // Check if P is inside
    // Sum of signed angles
    double sum_ang = 0;
    for(int i=0; i<n; i++) {
        Point p1 = poly[i];
        Point p2 = poly[(i+1)%n];
        double a1 = atan2(p1.y - py, p1.x - px);
        double a2 = atan2(p2.y - py, p2.x - px);
        double d = a2 - a1;
        while(d <= -M_PI) d += 2*M_PI;
        while(d > M_PI) d -= 2*M_PI;
        sum_ang += d;
    }
    
    bool inside = (abs(abs(sum_ang) - 2*M_PI) < 1e-5);
    
    if (!inside) {
        cout << fixed << setprecision(15) << 2 * M_PI << endl;
    } else {
        // P inside. Find max angular gap between vertices.
        vector<double> angles;
        for(int i=0; i<n; i++) {
            angles.push_back(atan2(poly[i].y - py, poly[i].x - px));
        }
        sort(angles.begin(), angles.end());
        double max_gap = 0;
        for(int i=0; i<n; i++) {
            double diff = angles[(i+1)%n] - angles[i];
            if (diff < 0) diff += 2 * M_PI;
            if (diff > max_gap) max_gap = diff;
        }
        cout << fixed << setprecision(15) << max_gap << endl;
    }
}

// ==========================================================
// Problem I: Same, In A Sense
// ==========================================================
void solve_I() {
    long long x, y;
    if (!(cin >> x >> y)) return;
    if (x == y) { cout << 1 << endl; return; } // Should not happen
    if (x > y) swap(x, y); // x < y
    
    // Logic: check divisors of y - x
    long long diff = y - x;
    long long ans = -1;
    
    // We want smallest k. The problem says "Any such k". Output "arbitrary"?
    // "If exists, output any such k".
    // Wait, problem text: "Output any such k". OK.
    // We try to find a valid k from divisors of y-x.
    // Divisors can be large. Just iterating up to sqrt(diff).
    
    vector<long long> divisors;
    for(long long i=1; i*i <= diff; i++) {
        if(diff % i == 0) {
            divisors.push_back(i);
            if(i*i != diff) divisors.push_back(diff/i);
        }
    }
    sort(divisors.begin(), divisors.end());
    
    for(long long k : divisors) {
        // Condition: k <= x?
        // If k <= x: x%k + k%x = x%k + k? No.
        // Wait, the logic derived was:
        // Case 1: x < k <= y. Then y%k = x. k divides y-x.
        // Check if x < k <= y AND y%k == x. (y%k == x is guaranteed if k|y-x and k>x)
        // Case 2: k <= x. Then k|y-x is required.
        // Check condition directly: (x%k + k%x) == (y%k + k%y)
        
        long long lhs = (x % k) + (k % x);
        long long rhs = (y % k) + (k % y);
        if (lhs == rhs) {
            cout << k << endl;
            return;
        }
    }
    
    cout << -1 << endl;
}

// ==========================================================
// Main Dispatcher
// ==========================================================

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Heuristic to detect problem based on input pattern is difficult.
    // But online judges execute one problem code.
    // I will use #ifdef or similar if compiling locally, but here I just put everything.
    // However, the prompt asks to "solve all".
    // I'll provide a template that can run the examples if pasted into a solution for a specific problem.
    // Since I cannot know which problem is being run, I can't put them all in one main without a selector.
    // BUT typically, "Problem X" solutions are separate.
    // I will write the Main to assume it's running specific logic based on manual selection or input detection?
    // Input detection is unreliable.
    // I will print all solutions in a way that the user can copy-paste the function body.
    
    // To make this functional for the user, I'll output the solution for "Problem A" by default?
    // No, that's useless.
    // I'll assume the user will copy the `solve_X` function content into their `main`.
    
    // For demonstration, I will read T and call solve_X for the problem that looks like it matches the input?
    // Let's implement logic to detecting problem A vs B etc?
    // A: T, then n, then array.
    // B: T, then n, then array. Similar.
    // E: just l, r.
    // This is risky.
    
    // Recommendation: The user should take the specific `solve_X` function and use it.
    // I will output a commented guide.
    
    int t = 1; 
    // Uncomment the solver you need:
    
    // For A:
    // cin >> t; while(t--) solve_A();
    
    // For B:
    // cin >> t; while(t--) solve_B();
    
    // For C: ...
    
    // For E:
    // solve_E(); // No T
    
    // For F:
    // cin >> t; while(t--) solve_F();

    // For G:
    // cin >> t; while(t--) solve_G();
    
    // For I:
    // cin >> t; while(t--) solve_I();
    
    // For D:
    // cin >> t; while(t--) solve_D();

    return 0;
}