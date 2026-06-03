//2026/4/16
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll a[101], b[101];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  ll inum = 0, p1 = 0, p2 = 1;
  for(int i = 1; i <= n; ++i) {
    string s; cin >> s;
    int sep = s.find('/');
    a[i] = stoll(s.substr(0, sep));
    b[i] = stoll(s.substr(sep+1));
    ll gd = gcd(a[i], b[i]);
    a[i] /= gd; b[i] /= gd;
    gd = gcd(p2, b[i]);
    ll gb = b[i]/gd, gp = p2/gd;
    p1 = p1*gb+a[i]*gp;
    p2 *= gb;
    inum += p1/p2;
    p1 %= p2;
    gd = gcd(p1, p2);
    p1 /= gd; p2 /= gd;
  }
  if(inum || !p1) cout << inum;
  if(p1) {
    if(inum) cout << ' ';
    cout << p1 << '/' << p2;
  } 
  cout << endl;
  return 0;
}