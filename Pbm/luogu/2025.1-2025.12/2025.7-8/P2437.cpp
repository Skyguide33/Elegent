//2025/7/23
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class bignum {
public:
  vector<int> num;
  bignum() {};
  bignum(ll snum) {
    while(snum) {
      num.push_back(snum%10);
      snum /= 10;
    }
  }
  friend bignum operator + (const bignum& a, const bignum& b) {
    int lena = a.num.size(), lenb = b.num.size(), len = max(lena, lenb);
    bignum res; res.num.resize(len);
    for(int i = 0; i < len; ++i) {
      if(i < lena) res.num[i] += a.num[i];
      if(i < lenb) res.num[i] += b.num[i];
    }
    int r = 0, i = 0;
    while(i < len) {
      r += res.num[i];
      res.num[i] = r % 10;
      r /= 10;
      ++i;
    }
    if(r) res.num.push_back(r);
    return res;
  }
  friend ostream& operator << (ostream& out, const bignum& a) {
    int len = a.num.size();
    for(int i = len-1; i >= 0; --i) out << a.num[i];
    return out;
  }
};

bignum a[1001];

void solve() {
  int m, n; cin >> m >> n;
  a[m] = a[m+1] = bignum(1);
  for(int i = m+2; i <= n; ++i) a[i] = a[i-1]+a[i-2];
  cout << a[n] << '\n';
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; //cin >> T;
  while(T--) solve();
  return 0;
}