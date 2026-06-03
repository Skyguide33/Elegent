//2025/3/12 3/13 rewrite 生日蛋糕
#include <cstdio>

int N, M, ans = 1e9, sk[16], vk[16];
/*dfs(m,r,h,s,v) i当前层数-1, 当前层半径, 当前层高度, s当前层及以下的总表面积, v当前层及以下的总体积
结束条件: m == 0 且 v == N
剪枝1: r < m+1, h < m+1
剪枝2: 当s+sk[m] > ans
剪枝3: 当v+vk[m] > n
*/
int min(int a, int b) { 
  if(a < b) return a;
  return b;
}
void dfs(int m, int r, int h, int s, int v) {
  int MAX_h = h;
  if(m == 0) {
     if(v == N) ans = min(ans, s);
     return;
  }
  if(v + vk[m-1] > N) return;
  if(2*(N-v)/r + s >= ans) return;
  for(int i = r-1; i >= m; i--) {
    if(M == m) s = i*i;
    MAX_h = min(h-1, (N-vk[m-1]-v)/i/i);
    for(int j = MAX_h; j >= m; j--) {
      dfs(m-1, i, j, s+2*i*j, v+i*i*j);
    }
  }
  return;
}

int main() {
  scanf("%d %d", &N, &M);
  for(int i = 1; i <= M; i++) {
    sk[i] = sk[i-1] + 2*i*i;
    vk[i] = vk[i-1] + i*i*i;
  }
  dfs(M,N,N,0,0);
  if(ans == 1e9) printf("0\n");
  else printf("%d\n", ans);
  return 0;
}