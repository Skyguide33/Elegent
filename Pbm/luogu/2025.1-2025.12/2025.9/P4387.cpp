//2025/9/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[100005], b[100005], st[100005];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) cin >> b[i];
  int top = 0, pb = 1;
  for(int i = 1; i <= n; ++i) {
    st[++top] = a[i];
    while(pb <= n && b[pb] == st[top]) {
      --top; ++pb;
    }
  }
  if(pb > n) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) solve();
  return 0;
}