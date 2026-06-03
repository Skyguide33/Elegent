//2025/8/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int s[200005], d[200005], ans;

int find_set(int x) {
  if(x != s[x]) {
    int t = s[x];
    s[x] = find_set(s[x]);
    d[x] += d[t];
  }
  return s[x];
}

void merge_set(int a, int b, int v) {
  int roota = find_set(a), rootb = find_set(b);
  if(roota == rootb) {
    if(d[a]-d[b] != v) ++ans;
  } else {
    s[roota] = rootb;
    d[roota] = d[b]-d[a]+v;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; 
  while(cin >> n >> m) {
    for(int i = 0; i <= n; ++i) { s[i] = i; d[i] = 0; }
    ans = 0;
    while(m--) {
      int a, b, v; cin >> a >> b >> v;
      merge_set(a-1, b, v);
    }
    cout << ans << endl;
  }
  return 0;
}