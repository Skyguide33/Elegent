//2026/2/10
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int a, b; cin >> a >> b;
  int n = a+b;
  int up, lw;
  char upc, lwc;
  if(a > b) up = a, upc = '0';
  else up = b, upc = '1';
  lw = n-up; lwc = ((upc-'0')^1)+'0';
  int blklen = up/(lw+1);
  int blk1cnt = up%(lw+1), blkcnt = lw+1-blk1cnt;
  string blks, blk1s;
  for(int i = 1; i <= blklen; ++i) blks += upc;
  blk1s = blks+upc;
  string ans = blks; --blkcnt;
  while(blkcnt--) ans += lwc+blks;
  while(blk1cnt--) ans += lwc+blk1s;
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}