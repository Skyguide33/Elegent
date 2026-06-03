//2025/11/20
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int pw[32], seqx[32], cnt;

void solve() {
  int a, b; cin >> a >> b;
  cnt = 0;
  for(int i = 0; i < 32; ++i) {
    if(a >= pw[i]) {
      if((a&pw[i]) != (b&pw[i])) seqx[cnt++] = pw[i];
    } else {
      if(b >= pw[i]) {
        cout << -1 << endl;
        return;
      } else break;
    }
  }
  cout << cnt << endl;
  if(cnt) {
    for(int i = 0; i < cnt; ++i) cout << seqx[i] << ' ';
    cout << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  pw[0] = 1;
  for(int i = 1; i < 32; ++i) pw[i] = pw[i-1]<<1;
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}