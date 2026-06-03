//2026/2/8
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

string add(string a, string b) {
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  size_t len = max(a.length(), b.length())+1;
  while(a.length() < len) a += '0';
  while(b.length() < len) b += '0';
  for(size_t i = 0; i < len; ++i) {
    a[i] += b[i]-'0';
    a[i+1] += (a[i]-'0')/10;
    a[i] = (a[i]-'0')%10+'0';
  }
  while(a.length() > 1 && a.back() == '0') a.pop_back();
  reverse(a.begin(), a.end());
  return a;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string a, b; cin >> a >> b;
  cout << add(a, b) << endl;
  return 0;
}