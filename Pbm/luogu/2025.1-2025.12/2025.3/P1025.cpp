//2025/3/11
#include <cstdio>

int n,k;
/*dfs(i,j,k) i剩余的未划分的数，j已被划分的数中的最大数，k剩余划分次数
终止条件 k==1
为保证结果不重复，要求下一个划分的数不小于上一个划分的数，且最小划分数不能小于1
i/k >= 1 && i/k >= j
为保证此次划分不会导致下一次划分不符合上述要求，需满此次划分数x满足x<=(i-x)/(k-1)
初始状态dfs(n,1,k)
*/
int dfs(int i, int j, int k) {
  if(k == 1) return 1;
  int ans = 0;
  for(int x = j; x <= (i-x)/(k-1); x++) {
    ans += dfs(i-x,x,k-1);
  }
  return ans;
}

int main() {
  scanf("%d %d", &n, &k);
  printf("%d\n", dfs(n,1,k));
  return 0;
}