//2025/5/26
#include <bits/stdc++.h>
using namespace std;

struct num{ int a, b; } c[200005];
int cnt[10];

bool cmp(num x, num y) { return x.b < y.b; }
int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> c[i].a >> c[i].b;
    ++cnt[c[i].a];
  }
  int tag = n / 10, ans = 0;
  sort(c+1, c+n+1, cmp);
  for(int i = 1; i <= n; ++i) {
    if(cnt[c[i].a] > tag) {
      ans += c[i].b;
      --cnt[c[i].a];
      for(int i = 0; i < 10; ++i) {
        if(cnt[c[i].a] < tag) {
          ++cnt[c[i].a]; 

          break;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}