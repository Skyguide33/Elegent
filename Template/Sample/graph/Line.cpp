//
#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
using ll = long long;
const int N = 2e5 + 5;

struct line {
    int x1, x2, y;
    int tag;
    bool operator<(line& t) {
        return y < t.y;
    }
}L[N];

struct tree {
    int l, r;
    int len, cnt;
}tr[N * 8];
int X[N];

void up(int u) {
    int l = tr[u].l, r = tr[u].r;
    if (tr[u].cnt)tr[u].len = X[r + 1] - X[l];
    else tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
}

void build(int u, int l, int r) {
    tr[u] = { l,r,0,0 };
    if (l == r)return;
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

void change(int u, int l, int r, int tag) {
    if (l > tr[u].r || r < tr[u].l)return;
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].cnt += tag;
        up(u);
        return;
    }
    change(u << 1, l, r, tag);
    change(u << 1 | 1, l, r, tag);
    up(u);
}


signed main() {
    int n, x1, x2, y1, y2;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        L[i] = { x1,x2,y1,1 };
        L[i + n] = { x1,x2,y2,-1 };
        X[i] = x1, X[i + n] = x2;
    }
    n <<= 1;
    sort(L + 1, L + n + 1);
    sort(X + 1, X + n + 1);
    int m = unique(X + 1, X + n + 1) - X - 1;
    build(1, 1, m - 1);

    ll ans = 0;
    for (int i = 1;i < n;i++) {
        int l = lower_bound(X + 1, X + m + 1, L[i].x1) - X;
        int r = lower_bound(X + 1, X + m + 1, L[i].x2) - X;
        change(1, l, r - 1, L[i].tag);
        ans += 1LL * tr[1].len * (L[i + 1].y - L[i].y);
    }
    cout << ans << '\n';
    return 0;
}