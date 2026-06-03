//2026/5/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[100005];

void solve() {
  int n; cin >> n;
  priority_queue<int> q;
  int minn = 1e9;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    q.push(a[i]);
    minn = min(minn, a[i]);
  }
  int ans = 0;
  while((minn%2 && q.top()-minn > 1) || (minn%2 == 0 && q.top() != minn)) {
    int u = q.top(); q.pop();
    if(u%2) {
      u = (u+1)/2;
      ans += 2;
    } else {
      u /= 2;
      ++ans;
    }
    minn = min(minn, u);
    q.push(u);
  }
  if(q.top() != minn) {
    int add1 = n;
    while(q.top() != minn) {
      --add1;
      q.pop();
    }
    if(minn == 1) ans += min(add1, n-add1);
    else ans += add1;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}