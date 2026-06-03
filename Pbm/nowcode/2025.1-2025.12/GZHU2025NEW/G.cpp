//2025/12/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'



int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string a, b; cin >> a >> b;
  int aa = 0, ab = 0, ac = 0, ba = 0, bb = 0, bc = 0;
  for(int i = 0; i < 2; ++i) {
    if(a[i] == 'A') ++aa;
    else if(a[i] == 'B') ++ab;
    else ++ac;
  }
  for(int i = 0; i < 2; ++i) {
    if(b[i] == 'A') ++ba;
    else if(b[i] == 'B') ++bb;
    else ++bc;
  }
  if(aa && ba) cout << 'A';
  if(ab && bb) cout << 'B';
  if(ac && bc) cout << 'C';
  cout << endl;
}