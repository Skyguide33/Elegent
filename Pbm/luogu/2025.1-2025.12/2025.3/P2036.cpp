//2025/3/21
#include <bits/stdc++.h>
using namespace std;

int n, s[10], b[10], ans = 1e9;

void dfs(int num, int start, int sums, int sumb) {
  if(num == 0) {
    ans = min(ans, abs(sums-sumb));
    return;
  }
  for(int i = start; i <= n-num; i++) 
    dfs(num-1, i+1, sums*s[i], sumb+b[i]);
  return;
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> s[i] >> b[i];
    ans = min(ans, abs(s[i]-b[i]));
  }
  for(int i = 2; i <= n; i++) dfs(i, 0, 1, 0);
  cout << ans << endl;
  return 0;
}