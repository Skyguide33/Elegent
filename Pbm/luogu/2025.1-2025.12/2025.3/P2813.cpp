//2025/3/24
#include <bits/stdc++.h>
using namespace std;

bool cmp(int x, int y) { return x > y; }

int d[100005], a[100005];

int main() {
  int M, N, ans = 0; 
  cin >> M >> N;
  for(int i = 0; i < M; i++) cin >> d[i];
  for(int i = 0; i < N; i++) {
    cin >> a[i];
    ans += a[i];
  }
  sort(d, d+M);
  sort(a, a+N);
  for(int i = 0, tag = 0; tag < M; tag++) {
    while(i < N && a[i] <= d[tag]) i++;
    if(i >= N) {
      cout << 0 << endl;
      return 0;
    }
    ans -= a[i++];
  }
  cout << ans << endl;
  return 0;
}