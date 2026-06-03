//2025/11/30
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  int ans = n*m/gcd(n, m);
  cout << n*m/gcd(n, m) << endl;
  vector<int> a(ans*2+2), b(ans*2+2);
  char tt; 
  for(int i = 1; i <= n; ++i) cin >> tt, a[i] = tt-'0';
  for(int i = 1; i <= m; ++i) cin >> tt, b[i] = tt-'0';
  for(int i = n+1; i <= ans+1; ++i) a[i] = a[(i-1)%n+1];
  for(int i = m+1; i <= ans+1; ++i) b[i] = b[(i-1)%m+1];
  vector<int> c(ans*2+2);
  for(int i = 2*ans; i >= 1; --i) {
    if(a[i]-b[i] < 0) --a[i-1], a[i] += 10;
    c[i] = a[i]-b[i];
  }
  for(int i = 1; i <= ans; ++i) cout << c[i];
  cout << endl;
  return 0;
}