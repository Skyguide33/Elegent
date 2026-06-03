//2026/4/16
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T, S, t; cin >> T >> S >> t;
  if(S == 1) {
    if(T > 35 && t >= 33) cout << "Bu Tie" << endl << T << endl;
    else cout << "Bu Re" << endl << t << endl;
  } else {
    if(T > 35 && t >= 33)  cout << "Shi Nei" << endl << T << endl;
    else cout << "Shu Shi" << endl << t << endl;
  }
  return 0;
}