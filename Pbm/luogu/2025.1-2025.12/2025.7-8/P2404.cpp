//2025/8/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

char ans[17], tail;

void dfs(int n, int pre) {
  if(n == 0 && tail > 3) {
    ans[tail-1] = '\0';
    cout << ans << endl;
    return;
  }
  if(n < pre) return;
  for(int i = pre; i <= n; ++i) {
    ans[tail++] = i+'0';
    ans[tail++] = '+';
    dfs(n-i, i);
    tail -= 2;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  dfs(n, 1);
  return 0;
}