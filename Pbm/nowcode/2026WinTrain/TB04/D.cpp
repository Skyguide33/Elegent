//2026/2/10 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lll __int128_t
#define endl '\n'

lll read() {
    lll x=0;bool f=0;char c=getchar();
    while (c<'0'||c>'9'){if (c=='-')f=1;c=getchar();}
    while (c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    return f?-x:x;
}

inline void write(lll x) {
     if(x<0) putchar('-'),x=-x;
     if(x>9) write(x/10);
     putchar(x%10+'0');
}


// 拓展欧几里得定理
lll exgcd(lll a, lll b, lll &x, lll &y) {
  if(b == 0) { x = 1; y = 0; return a; }
  lll d = exgcd(b, a%b, y, x);
  y -= a/b*x;
  return d;
}

int cnt;

void solve() {
  ++cnt;
  ll ds, as, ss; cin >> ds >> as >> ss;
  lll d = ds, a = as, s = ss;
  lll x, y;
  lll gd = exgcd(a, s, x, y);
  if(d%gd) {
    cout << "No" << endl;
    return;
  }
  lll c1 = d/gd*x, c2 = d/gd*y;
  lll agd = a/gd, sgd = s/gd;
  lll c11, c21, c12, c22;
  auto method1 = [&]()->void {
    if(c1 >= c2) {
      lll dist = c1-c2;
      lll pp = dist/(agd+sgd);
      c11 = c1-pp*sgd, c21 = c2+pp*agd;
      c12 = c11-sgd, c22 = c21+agd;
    } else {
      lll dist = c2-c1;
      lll pp = dist/(agd+sgd);
      c11 = c1+pp*sgd, c21 = c2-pp*agd;
      c12 = c11+sgd, c22 = c21-agd;
    }
  };
  auto method2 = [&]()->void {
    if(c1 >= c2) {
      lll l = 0, r = c1/sgd;
      while(l < r) {
        lll mid = (l+r+1)/2;
        lll c1_n = c1-mid*sgd;
        lll c2_n = c2+mid*agd;
        if(c1_n >= c2_n) l = mid;
        else r = mid-1;
      }
      c11 = c1-l*sgd, c21 = c2+l*agd;
      c12 = c11-sgd, c22 = c21+agd;
    } else {
      lll l = 0, r = c2/agd;
      while(l < r) {
        lll mid = (l+r+1)/2;
        lll c2_n = c2-mid*agd;
        lll c1_n = c1+mid*sgd;
        if(c2_n >= c1_n) l = mid;
        else r = mid-1;
      }
      c11 = c1+l*sgd, c21 = c2-l*agd;
      c12 = c11+sgd, c22 = c21-agd;
    }
  };
  method1();
  if(min(c11, c21) < 0 && min(c12, c22) < 0) cout << "No" << endl;
  else {
    cout << "Yes" << endl;
    if(min(c11, c21) >= 0 && min(c12, c22) >= 0) {
      if(max(c11, c21) < max(c12, c22)) cout << (ll)c11 << ' ' << (ll)c21 << endl;
      else cout << (ll)c12 << ' ' << (ll)c22 << endl;
    } else if(min(c11, c21) >= 0) cout << (ll)c11 << ' ' << (ll)c21 << endl;
    else cout << (ll)c12 << ' ' << (ll)c22 << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) solve();
  return 0;
}