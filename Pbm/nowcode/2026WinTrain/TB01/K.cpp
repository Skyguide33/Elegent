//2026/2/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[101], n;
bool flag = 0;

void dfs(int idx, int sum, int mul) {
  if(sum && sum < mul) return;
  // cout << format("idx={0}, sum={1}, mul={2}", idx, sum, mul) << endl;
  if(idx == n) {
    if(sum == mul) {
      flag = 1;
    }
    return;
  }
  for(int i = a[idx]+1; i <= n; ++i) {
    if(flag) break;
    a[idx+1] = i;
    dfs(idx+1, sum+i, mul*i);
  }
}

void solve() {
  cin >> n;
  if(n == 1) cout << "YES\n1" << endl;
  else if(n == 3) cout << "YES\n1 2 3" << endl;
  else cout << "NO" << endl;
  // for(n = 1; n <= 100; ++n) {
  //   flag = 0;
  //   dfs(0, 0, 1);
  //   if(flag) {
  //     cout << "YES" << endl;
  //     for(int i = 1; i <= n; ++i) cout << a[i] << ' ';
  //     cout << endl;
  //   } else cout << "NO" << endl;
  // }
 

}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}