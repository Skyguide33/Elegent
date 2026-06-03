//2025/11/16
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005], pre[200005], nxt[200005], b[200005];

bool cmp(int x, int y) { return a[x] < a[y]; }

void solve() {
  int n; cin >> n;
  for(int i = 0; i < n; ++i) {
    b[i] = i;
    cin >> a[i]; nxt[i] = (i+1)%n; pre[i] = (i-1+n)%n;
  }
  sort(b, b+n, cmp);
  ll cnt = 0;
 
  // cout << endl;
  for(int i = 0; i < n-1; ++i) {
    // for(int j = b[i];; j = nxt[j]) {
    //   cout << a[j] << ' ';
    //   if(nxt[j] == b[i]) break;
    // }
    // cout << endl;
    cnt += max(a[b[i]], min(a[pre[b[i]]], a[nxt[b[i]]]));
    // cout << cnt << ' ' << endl;
    pre[nxt[b[i]]] = pre[b[i]];
    nxt[pre[b[i]]] = nxt[b[i]];
  }
  cout << cnt << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}