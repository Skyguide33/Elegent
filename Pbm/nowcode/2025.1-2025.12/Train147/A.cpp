//2025/12/19
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, r; cin >> n >> r;
  vector<int> a(n+1, 1);
  a[n] = -n;
  for(int i = n-r+1; i <= 2*n-r; ++i) cout << a[(i-1)%n+1] << ' ';
  cout << endl;
  return 0;
}