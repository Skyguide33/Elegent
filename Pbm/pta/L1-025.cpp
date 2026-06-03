//2026/4/17
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int valid(string s) {
  if(s[0] == ' ') s.erase(s.begin());
  for(char ch: s) {
    if(!isdigit(ch)) return 3000;
  }
  int num = stoi(s);
  if(num == 0 || num > 1000) return 3000;
  return num;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string sa, sb; cin >> sa;
  getline(cin, sb);
  int a = valid(sa), b = valid(sb), sum = a+b;
  if(a > 1000) cout << '?';
  else cout << a;
  cout << " + ";
  if(b > 1000) cout << '?';
  else cout << b;
  cout << " = ";
  if(sum > 2000) cout << '?' << endl;
  else cout << sum << endl;
  return 0;
}