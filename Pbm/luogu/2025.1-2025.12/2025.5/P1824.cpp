//2025/5/7
#include <bits/stdc++.h>
using namespace std;

int x[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int N, C; cin >> N >> C;
  for(int i = 1; i <= N; ++i) cin >> x[i];
  sort(x+1, x+N+1);
  int l = 0, r = x[N];
  while(l < r) {
    int mid = l + (r-l+1)/2;
    int cnt = C-1, pre = 1;
    for(int i = 2; i <= N; ++i) {
      if(cnt == 0) break;
      else if(x[i] - x[pre] >= mid) {
        pre = i; --cnt;
      }
    }
    if(cnt == 0) l = mid;
    else r = mid-1;
  }
  cout << l << endl;
  return 0;
}