//2025/4/14
#include <bits/stdc++.h>
using namespace std;

long long a[200005], b[200005];
int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int N, M; cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    cin >> a[i];
    a[i] = a[i] * a[i];
  }
  sort(a+1, a+N+1);
  for(int i = 2; i <= N; i++) b[i] = a[i] - a[i-1];
  for(int i = 2; i <= N; i++) b[i] += b[i-1];
  long long ans = b[M];
  for(int i = M+1; i <= N; i++) {
    ans = min(ans, b[i]-b[i-M+1]);
  }
  cout << ans << endl;
  return 0;
}