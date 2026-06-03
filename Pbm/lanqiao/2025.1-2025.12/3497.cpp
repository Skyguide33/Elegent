//2025/3/5 有奖问答
#include <iostream>
using namespace std;

int ans;

void dfs(int n, int sum) {
  if(sum == 100 || n >= 31) return;
  if(sum == 70) ans++;
  dfs(n+1, sum+10);
  dfs(n+1, 0);
  return;
}

int main() {
  dfs(0,0);
  cout << ans << endl;
  return 0;
}