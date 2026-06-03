//2026/2/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string s; cin >> s;
  if(*s.begin() == *s.rbegin()) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}