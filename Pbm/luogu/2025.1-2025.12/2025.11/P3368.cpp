//2025/11/9
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define lowbit(x) (x&(-x))
#define N 500005

ll a[N], b[N], n;

void update(ll *tree, int x, int d) {
  while(x <= n) {
    tree[x] += d;
    x += lowbit(x);
  }
}

ll sum(ll *tree, int x) {
  ll res = 0;
  while(x) {
    res += tree[x];
    x -= lowbit(x);
  }
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int m, op, x, y, k; cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    cin >> x; 
    update(a, i, x);
    update(a, i+1, -x);
    update(b, i, x*(i-1));
    update(b, i+1, -x*i);
  }
  while(m--) {
    cin >> op >> x;
    if(op == 1) {
      cin >> y >> k;
      update(a, x, k);
      update(a, y+1, -k);
      update(b, x, k*(x-1));
      update(b, y+1, -k*y);
    } else cout << x*sum(a, x)-sum(b, x)-(x-1)*sum(a, x-1)+sum(b, x-1) << endl;
    
  }
  return 0;
}