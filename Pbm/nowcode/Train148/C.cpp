//2026/1/23
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int p[200005], id[200005], d[200005], repr[200005], pos[200005], ans[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> p[i], pos[p[i]] = i;
  for(int i = 1; i <= n; ++i) cin >> id[i];
  for(int i = 1; i <= n; ++i) cin >> d[i];
  for(int i = 1; i <= n; ++i) {
    ans[i] = ans[i-1];
    if(!repr[id[i]]) {
      int ned_repr_num = p[id[i]];
      int now_pos = id[i];
      while(d[now_pos] != ned_repr_num) {
        repr[now_pos] = 1;
        ++ans[i];
        now_pos = pos[d[now_pos]];
      }
      repr[now_pos] = 1;
      ++ans[i];
    }
    cout << ans[i] << ' ';
  }
  cout << endl;
  return 0;
}