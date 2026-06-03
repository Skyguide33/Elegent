#include <cstdio>

int ans, x[25], n, k;

bool isprime(int num) {
  if(num == 1) return 0;
  if(num == 2) return 1;
  for(int i = 2; i * i <= num; i += 1)
    if(num % i == 0) return 0;
  return 1;
}
/*dfs(t, sum, sid) t已组合的数的个数 sum已组合的数的和 sid这一次选取元素的x数组起始位置下标
结束条件 t == k
还需组合数的个数 k-t
*/
void dfs(int t, int sum, int sid) {
  if(t == k) {
    if(isprime(sum)) ans++;
    return;
  }
  for(int i = sid; i <= n-k+t+1; i++) {
    dfs(t+1, sum+x[i], i+1);
  }
  return;
}
int main() {
  scanf("%d %d", &n, &k);
  for(int i = 1; i <= n; i++) scanf("%d", &x[i]);
  dfs(0, 0, 1);
  printf("%d\n", ans);
  return 0;
}