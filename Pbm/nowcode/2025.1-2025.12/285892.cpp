#include <bits/stdc++.h>
#define ls (u << 1)
#define rs (u << 1 | 1)
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 3e5 + 10;

struct qy {
    int opt, l, r;
} a[N];
struct node {
    int l, r;       // 管理的左右区间，用离散化之后的值代替
    int ranL, ranR; // 表示管理的左右区间
    int num0, num1; // 将当前区间修改为0开头的好串和1开头的好串的修改次数
    int lazy_tag;   // 更新区间翻转的lazy是第几次操作
    int lazy_1;     // 更新区间为1的lazy是第几次操作
} tr[N << 2];

vector<int> v;
int getIdx(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

void calc(int u, int lt, int l1) {
    int len = tr[u].ranR - tr[u].ranL + 1;
    if (lt && l1 && lt > l1) {
        // 先1后翻，等价于赋0
        tr[u].num0 = len / 2;
        tr[u].num1 = (len + 1) / 2;
    } else if (l1) {
        // 剩下的情况就是翻后1或者有1无翻，直接赋值为1
        tr[u].num0 = (len + 1) / 2;
        tr[u].num1 = len / 2;
    } else if (lt) {
        swap(tr[u].num0, tr[u].num1);
    }
}

void push_down(int u) {
    if (tr[u].lazy_1) tr[ls].lazy_1 = tr[rs].lazy_1 = tr[u].lazy_1;
    if (tr[u].lazy_tag) {
        // down下去取反操作时，注意看最近的操作是不是取反
        // 如果是的话就需要更新子区间的lazy_tag为0
        if (tr[ls].lazy_1 < tr[ls].lazy_tag) tr[ls].lazy_tag = 0;
        else tr[ls].lazy_tag = tr[u].lazy_tag;
        if (tr[rs].lazy_1 < tr[rs].lazy_tag) tr[rs].lazy_tag = 0;
        else tr[rs].lazy_tag = tr[u].lazy_tag;
    }
    calc(ls, tr[u].lazy_tag, tr[u].lazy_1);
    calc(rs, tr[u].lazy_tag, tr[u].lazy_1);
    tr[u].lazy_1 = tr[u].lazy_tag = 0;
}

void push_up(int u) {
    tr[u].ranL = tr[ls].ranL, tr[u].ranR = tr[rs].ranR;
    // 更新num0
    tr[u].num0 = tr[ls].num0;
    int len_l = tr[ls].ranR - tr[ls].ranL + 1;
    if (len_l & 1) tr[u].num0 += tr[rs].num1;
    else tr[u].num0 += tr[rs].num0;
    // 更新num1
    tr[u].num1 = tr[ls].num1;
    if (len_l & 1) tr[u].num1 += tr[rs].num0;
    else tr[u].num1 += tr[rs].num1;
}

void build(int u, int l, int r) {
    tr[u].l = l, tr[u].r = r;
    if (l == r) {
        tr[u].ranL = v[l - 1];
        tr[u].ranR = v[l] - 1;
        int len = tr[u].ranR - tr[u].ranL + 1;
        tr[u].num0 = len / 2;
        tr[u].num1 = (len + 1) / 2;
        return ;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    push_up(u);
}

void update(int u, int st, int ed, int opt, int num_opt) {
    // opt=1表示更新当前区间为1，否则就是翻转
    int l = tr[u].l, r = tr[u].r;
    if (st <= l && r <= ed) {
        if (opt == 1) {
            tr[u].lazy_1 = num_opt;
            calc(u, 0, num_opt);
        }
        if (opt == 2) {
            if (tr[u].lazy_1 < tr[u].lazy_tag) tr[u].lazy_tag = 0;
            else tr[u].lazy_tag = num_opt;
            calc(u, num_opt, 0);
        }
        return ;
    }
    push_down(u);
    int mid = (l + r) / 2;
    if (st <= mid) update(ls, st, ed, opt, num_opt);
    if (ed > mid) update(rs, st, ed, opt, num_opt);
    push_up(u);
}

node query(int u, int st, int ed) {
    int l = tr[u].l, r = tr[u].r;
    if (st <= l && r <= ed) return tr[u];
    push_down(u);
    int mid = (l + r) >> 1;
    node ans;
    ans.num0 = -1;
    if (st <= mid) {
        node tmp = query(ls, st, ed);
        ans = tmp;
    }
    if (ed > mid) {
        node tmp = query(rs, st, ed);
        if (ans.num0 == -1) ans = tmp;
        else {
            // 更新答案的num0
            int lenl = ans.ranR - ans.ranL + 1;
            if (lenl & 1) ans.num0 += tmp.num1;
            else ans.num0 += tmp.num0;
            // 更新答案的num1
            if (lenl & 1) ans.num1 += tmp.num0;
            else ans.num1 += tmp.num1;
            ans.ranR = tmp.ranR;
        }
    }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int m, q;
    cin >> m >> q;
    for (int i = 1; i <= q; i ++ ) {
        cin >> a[i].opt >> a[i].l >> a[i].r;
        v.push_back(a[i].l);
        v.push_back(a[i].r + 1);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int n = v.size() - 1;
    build(1, 1, n);
    for (int i = 1; i <= q; i ++ ) {
        int opt = a[i].opt;
        int l = getIdx(a[i].l) , r = getIdx(a[i].r + 1) - 1;
        if (opt == 1) update(1, l, r, 1, i);
        else if (opt == 2) update(1, l, r, 2, i);
        else {
            node ans = query(1, l, r);
            cout << min(ans.num0, ans.num1) << endl;
        }
    }
    return 0;
}