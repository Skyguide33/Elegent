//2025/8/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct goods { ll w, v, c; } a[100005];
ll w[100005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i].w >> a[i].v >> a[i].c;
  }
  sort(a+1, a+n+1, [] (goods &x, goods &y) {
    return 1.*x.c/x.w < 1.*y.c/y.w;
  });
  for(int i = 2; i <= n; ++i)  w[i] = w[i-1]+a[i-1].w;
  ll ans = 0;
  for(int i = 1; i <= n; ++i)  ans += a[i].v-a[i].c*w[i];
  cout << ans << endl;
  return 0;
}