//2025/3/24
#include <bits/stdc++.h>
using namespace std;

int a[100005], b[100005];

int main() {
  int n, m; cin >> n >> m;
#if 0
  set<int>q;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= m; i++) {
    cin >> b[i];
    q.insert(b[i]);
  }
  for(int i = 1; i <= n; i++) {
    if(q.count(a[i])) cout << a[i] << ' ';
  }
  cout << endl;
#endif
#if 1
  map<int, bool> q;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= m; i++) {
    cin >> b[i];
    q[b[i]] = 1;
  }
  for(int i = 1; i <= n; i++) {
    if(q[a[i]]) cout << a[i] << ' ';
  }
  cout << endl;
#endif
  return 0;
}