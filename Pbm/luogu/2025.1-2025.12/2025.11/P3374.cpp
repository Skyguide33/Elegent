//2025/11/9
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define lowbit(x) (x&(-x))

ll a[500005], n;

void update(int x, int d) {
  while(x <= n) {
    a[x] += d;
    x += lowbit(x);
  }
}

ll query(int x) {
  ll res = 0;
  while(x) {
    res += a[x];
    x -= lowbit(x);
  }
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int m, op, x, y;
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) cin >> x, update(i, x);
  while(m--) {
    cin >> op >> x >> y;
    if(op == 1) update(x, y);
    else cout << query(y)-query(x-1) << endl;
  }
  return 0;
}