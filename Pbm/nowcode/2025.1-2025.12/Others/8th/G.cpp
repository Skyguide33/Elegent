//2025/8/7
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll ar[64], br[64];

string getbin(int e) {
  string res;
  bool sig = 0;
  if(e > 0) {
    while(e) {
      if(sig) {
        if(e % 2) {
          res.insert(res.begin(), '1');
          e += 1;
        } else res.insert(res.begin(), '0');
      } else {
        if(e % 2) res.insert(res.begin(), '1');
        else res.insert(res.begin(), '0');
      }
      e /= 2;
      sig ^= 1;
    }
  } else if(e < 0) {
    while(e) {
      if(!sig) {
        if(e % 2) {
          res.insert(res.begin(), '1');
          e -= 1;
        } else res.insert(res.begin(), '0');
      } else {
        if(e % 2) res.insert(res.begin(), '1');
        else res.insert(res.begin(), '0');
      }
      e /= 2;
      sig ^= 1;
    }
  } else return "0";
  
  return res;
}

void solve() {
  memset(ar, -1, sizeof(ar));
  memset(br, -1, sizeof(br));
  ar[0] = br[1] = 1;
  for(int i = 2; i < 64; i += 2) ar[i] = ar[i-2]*(-2);
  for(int i = 3; i < 64; i += 2) br[i] = br[i-2]*(-2);
  string x, y; cin >> x >> y;
  int lenx = x.length(), leny = y.length();
  int a = 0, b = 0, c = 0, d = 0;
  for(int i = 0; i < lenx; ++i) {
    if(x[lenx-i-1] == '1') {
      if(ar[i] != -1) a += ar[i];
      else b += br[i];
    } 
  }
  for(int i = 0; i < leny; ++i) {
    if(y[leny-i-1] == '1') {
      if(ar[i] != -1) c += ar[i];
      else d += br[i];
    } 
  }
  int e = a*c-2*b*d, f = a*d+b*c;
  // cout << "xy=" << x << ' ' << y << endl;
  // cout << "x=" << a << "+sqrt(-2)*" << b;
  // cout << ", y=" << c << "+sqrt(-2)*" << d;
  // cout << ", z=" << e << "+sqrt(-2)*" << f << endl;
  
  //通过 e、f转回sqrt(-2)进制
  
  string rese = getbin(e), resf = getbin(f);
  while(rese.length() < resf.length()) rese.insert(rese.begin(), '0');
  while(resf.length() < rese.length()) resf.insert(resf.begin(), '0'); 
  // cout << "res=" << rese << ' ' << resf << endl;
  int len = rese.length();
  string ans;
  for(int i = 0; i < len; ++i) {
    ans.push_back(resf[i]);
    ans.push_back(rese[i]);
  }
  while(ans.length() > 1 && ans.front() == '0') ans.erase(0, 1);
  cout << ans << endl;
} 

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}