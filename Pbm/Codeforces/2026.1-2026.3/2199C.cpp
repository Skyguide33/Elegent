//2026/3/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int k; cin >> k;
  if(k == 1) {
    cout << "YES" << endl << 1 << endl << '*' << endl << '.' << endl;
    return;
  } 
  string s1, s2;
  bool flag = 0;
  if((k-3)%5 == 0 || (k-6)%5 == 0) {
    k -= 3;
    s1 += "*.";
    flag = 1;
  } 
  if(k%5 == 0 || (k-3)%5 == 0) {
    int num = k/5;
    k -= num*5;
    for(int i = 1; i <= num; ++i) s1 += ".*."; 
    flag = 1;
  } 
  if(k == 3) s1 += ".*";
  if(flag) {
    cout << "YES" << endl << s1.length() << endl << s1 << endl;
    for(int i = s1.length(); i >= 1; --i) cout << '.';
    cout << endl;
  } else cout << "NO" << endl;
} 

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}