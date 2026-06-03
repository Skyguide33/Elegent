//2025/12/19
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define lowbit(x) (x&-(x))

int num;
int t[400005];

void change(int x, int d) {
  while(x <= num) {
    t[x] += d;
    x += lowbit(x);
  }
}

int query(int x) {
  int res = 0;
  while(x) {
    res += t[x];
    x -= lowbit(x);
  }
  return res;
}

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  vector<int> a(n+1), b(2*n);
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i < 2*n; ++i) b[i] = a[(i-1)%n+1]+b[i-1];
  auto c = b;
  sort(c.begin(), c.end());
  num = unique(c.begin(), c.end())-c.begin();
  for(int i = 0; i < 2*n; ++i) b[i] = lower_bound(c.begin(), c.begin()+num, b[i])-c.begin()+1;
  for(int i = 0; i < n; ++i) change(b[i], 1);
  int ans1 = 0, ans2 = 0;
  for(int i = 0; i < n; ++i) {
    change(b[i], -1);
    change(b[i+n], 1);
    int tt = query(num)-query(b[i]);
    if(tt > ans2) {
      ans1 = i; ans2 = tt;
    }
  }
  cout << ans1 << ' ' << ans2 << endl;
  return 0;
}