//2026/2/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

string s[101];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  int m = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> s[i];
    m = max(m, (int)s[i].length());
  }
  for(int i = 1; i <= n; ++i) {
    int len = (m-s[i].length())/2;
    for(int i = 1; i <= len; ++i) cout << '.';
    cout << s[i]; 
    for(int i = 1; i <= len; ++i) cout << '.';
    cout << endl;
  }
  return 0;
}