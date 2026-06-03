//2025/9/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll a[200005], stl[200005], str[200005], topl, topr;
set<ll> st;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll n, k; cin >> n >> k;
  for(ll i = 1; i <= n-2; ++i) st.insert(i);
  if(k < 3*n-1 || k > (1+n)*n/2+n) {
    cout << -1 << endl;
    return 0;
  } 
  k -= n*3-1;
  stl[++topl] = n-1; str[++topr] = n;
  for(ll i = n-2; i >= 2; i -= 2) {
    if(i <= k) {           
      stl[++topl] = i;
      st.erase(i);
      k -= i;
    } 
    if(i-1 <= k) {
      str[++topr] = i-1;
      st.erase(i-1);
      k -= i-1;
    }
  }
  if(k == 1) {
    stl[++topl] = 1;
    st.erase(1);
  }
  ll l = 1, r = n;
  while(topl) {
    a[l++] = stl[topl--];
  }
  while(topr) {
    a[r--] = str[topr--];
  }
  for(auto &x: st) {
    a[l++] = x;
  }
  for(ll i = 1; i <= n; ++i) cout << a[i] << ' ';
  cout << endl;
  return 0;
}