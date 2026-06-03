//2026/3/26
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define lowbit(x) (x&(-x))

ll bt[500005], n;

ll sum(int x) {
  ll res = 0;
  while(x) {
    res += bt[x];
    x -= lowbit(x);
  }
  return res;
}

void modify(int x, int k) {
  while(x <= n) {
    bt[x] += k;
    x += lowbit(x);
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int m; cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    int tt; cin >> tt;
    modify(i, tt);
  }
  while(m--) {
    int op, x1, x2; cin >> op >> x1 >> x2;
    if(op == 1) modify(x1, x2);
    else cout << sum(x2)-sum(x1-1) << endl;
  }
  return 0;
}