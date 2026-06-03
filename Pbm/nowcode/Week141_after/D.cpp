//2026/4/26
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[2000005];

int max_p(int num) {
  if(num == 1) return 1e9;
  ll b = num, p = 0;
  while(b <= 1e9) {
    ++p;
    b *= num;
  }
  return p;
} 

int fast_power(int b, int p) {
  int res = 1;
  while(p) {
    if(p&1) res *= b;
    b *= b;
    p >>= 1;
  }
  return res;
}

void solve() {
  int n; cin >> n;
  map<int, int> cnt;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    if(!cnt.contains(a[i])) cnt[a[i]] = 1;
    else ++cnt[a[i]];
  }
  if(cnt[1] >= 2) {
    cout << "YES" << endl;
    return;
  }
  sort(a+1, a+n+1);
  n = unique(a+1, a+n+1)-a-1;
  if(cnt[1] == 1) {
    for(int i = 1; i <= n; ++i) {
      if(cnt[a[i]] >= 2) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  set<int> st;
  for(int i = 1; i <= n; ++i) {
    int maxp = max_p(a[i]);
    int pos = upper_bound(a+1, a+n+1, maxp)-a-1;
    for(int j = 1; j <= pos; ++j) {
      if(a[j] != 1) {
        st.insert(fast_power(a[i], a[j]));
      }
    }
  }
  for(int i = 1; i <= n; ++i) {
    if(a[i] != 1 && st.contains(a[i])) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}