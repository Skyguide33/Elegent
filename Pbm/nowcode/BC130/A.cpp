//2026/3/20
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll n, m; cin >> n >> m;
  ll x = 0.8*m;
  if(m*4%5 != 0) ++x;
  cout << n*x << endl;
  return 0;
}