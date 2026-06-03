//2026/2/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string s;
  int sum = 0;
  while(cin >> s) {
    for(char ch: s) sum += ch;
  }
  cout << sum << endl;
  return 0;
}