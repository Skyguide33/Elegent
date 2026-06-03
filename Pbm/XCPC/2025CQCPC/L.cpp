//2026/5/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 998244353

int st[600005], top;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  ll num = 0;
  for(int i = 1; i <= n; ++i) {
    string s; cin >> s;
    if(s == "Push") {
      int x; cin >> x;
      st[++top] = x;
      num = (num+x)%MOD;
    } else if(s == "Pop") {
      num = (num-st[top--]+MOD)%MOD;
    } else {
      if(top < n-i) {
        for(int i = 1; i <= top; ++i) st[top+i] = st[i];
        top *= 2;
      } 
      num = num*2%MOD;
    }
    cout << num << endl;
  }
  return 0;
}