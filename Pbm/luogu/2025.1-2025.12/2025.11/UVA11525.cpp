//2025/11/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define lowbit(x) (x&(-x))
#define N 50005

int t[N], s[N], k;

void update(int pos) {
  while(pos <= k) {
    ++t[pos];
    pos += lowbit(pos);
  }
}

int query(int pos) {
  int res = 0;
  while(pos) {
    res += t[pos];
    pos -= lowbit(pos);
  }
  return res;
}

void solve() {
  memset(t, 0, sizeof(t));
  cin >> k;
  for(int i = 1; i <= k; ++i) cin >> s[i];
  int prer, tt;
  for(int i = 1; i <= k; ++i) {
    int r = s[i]+1;
    prer = r; r += query(r);
    while((tt = query(r)-query(prer))) {
      prer = r; 
      r += tt;
    }
    update(r);
    cout << r; if(i != k) cout << ' ';
  }
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}