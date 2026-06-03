//2025/12/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  if((n+2)%3) {
    cout << -1 << endl;
    return 0;
  } 
  cout << "1 ";
  for(int i = 2; i <= n; ++i) {
    if((i-1)%3) cout << i+1 << ' ';
    else cout << i-2 << ' '; 
  }
  cout << endl;
  return 0;
}