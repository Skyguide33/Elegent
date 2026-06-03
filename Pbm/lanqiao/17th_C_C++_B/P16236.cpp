//2026/4/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  string s; cin >> s;
  int cnt1 = 0, cnt2 = 0, cnt = 0;
  for(int i = 0; s[i]; ++i) {
    if(s[i] == 'L') ++cnt1;
    else if(s[i] == 'Q') ++cnt2;
    else ++cnt;
  }
  if(cnt1 > cnt2) swap(cnt1, cnt2);
  int d = cnt2-cnt1;
  int add1 = min(d, cnt);
  cnt -= add1;
  cnt1 += add1;
  int add2 = cnt/2, add3 = cnt-add2;
  cnt1 += add2; cnt2 += add3;
  cout << 1ll*cnt1*cnt2 << endl;
  return 0;
}