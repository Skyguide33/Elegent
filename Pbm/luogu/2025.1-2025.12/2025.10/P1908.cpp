//2025/10/16
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define lowbit(pre) ((pre)& -(pre))

int a[500005], b[500005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i]; b[i] = a[i];
  }
  sort(b+1, b+n+1);
  int num = unique(b+1, b+n+1)-b-1;
  for(int i = 1; i <= n; ++i) {
    a[i] = lower_bound(b+1, b+num+1, a[i])-b;
  }
  for(int i = 1; i <= n; ++i) b[i] = 0;
  ll ans = 0;
  
  for(int i = 1; i <= n; ++i) {
    int now = a[i]; 
    while(now <= n) {
      ++b[now];
      now += lowbit(now);
    }
    now = a[i]; 
    while(now) {
      ans -= b[now];
      now -= lowbit(now);
    }
  }
  ans += 1ll*(n+1)*n/2;
  cout << ans << endl;
  return 0;
}