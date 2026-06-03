//2025/12/26
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  string a, b; cin >> a >> b;
  bool ap = 0, bp = 0;
  if(a.back() == '+') {
    a.pop_back();
    ap = 1;
  } 
  if(b.back() == '+') {
    b.pop_back();
    bp = 1;
  } 
  int an = stoi(a), bn = stoi(b);
  if(an > bn || (an == bn && ap && !bp)) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}