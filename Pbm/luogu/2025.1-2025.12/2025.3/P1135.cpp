//2025/3/14
#include <cstdio>

int N, A, B, K[205], ans[205];

/*dfs(t,l) t已按次数 l当前层数
*/
void dfs(int t, int l) {
  if(ans[l] == 0) {
    ans[l] = t;
  }
  else if(t < ans[l]) {
    ans[l] = t;
    if(l == B) return;
  } else return;
  if(K[l] == 0) return; 
  if(l + K[l] <= N) dfs(t+1, l+K[l]);
  if(l - K[l] >= 1) dfs(t+1, l-K[l]);
  return;
}
int main() {
  scanf("%d %d %d", &N, &A, &B);
  for(int i = 1; i <= N; i++) scanf("%d", &K[i]);
  dfs(0, A);
  if(A == B) printf("0\n");
  else {
    if(ans[B] == 0) ans[B] = -1;
    printf("%d\n", ans[B]);
  }
  return 0;
}