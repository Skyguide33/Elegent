//2026/3/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  double p; cin >> p;
  p /= 100;
  double w2 = p, l1 = 1-p;
  double l2 = l1*p+w2*(1-p), l3 = l2*p;
  double w3 = w2*p, l4 = l3*p+w3*(1-p);
  double w4 = w3*p+l4*p;
  cout << setprecision(7) << fixed << w4 << endl;
  return 0;
}