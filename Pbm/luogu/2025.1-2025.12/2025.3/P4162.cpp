//2025/3/18
#include <bits/stdc++.h> 
using namespace std; 

/*思路：本题所求的距离是指在给出的N×M土地格子中，移除T块障碍物后可以相互连通的
土地格子之间的最大距离。所以可以分别以各个格子为起点，不重复地搜索四周的格子并记
下使起点与该格子联通所需移走的障碍物数目。对于每个起点，搜索结束后对四周各个所记
录的需移走障碍物数目不超过T的格子计算距离，最终得出距离最大值。

dfs(x, y, cnt) x,y坐标 cnt起点与该点连通至少移走障碍物的数量
*/

int n, m, t;
int a[31][31], d[31][31], v[31][31]; //a存储原土地格子障碍物情况
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; 
//方向向量，便于得到下一次搜索的坐标

void dfs(int x, int y, int cnt) {
  if(cnt > t || cnt >= d[x][y]) return;
  //剪枝1：移除障碍物的数量超过最大允许数量
  //剪枝2：该条从起点至此点的搜索路径移除障碍物的数量不是最少的
  d[x][y] = cnt;     //此处cnt必定小于d[x][y],更新d[x][y]
  for(int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i]; //得到搜索的下一个格子的坐标
    if(nx < 1 || nx > n || ny < 1 || ny > m || v[nx][ny]) continue;
    //检查坐标是否越界，以及是否被搜索过
    v[x][y] = 1; //标记当前坐标已被搜索
    dfs(nx, ny, cnt + a[nx][ny]); //搜索下一层
    v[x][y] = 0; //下层搜索完毕后恢复现场
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m >> t;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      char ch; cin >> ch; a[i][j] = ch - '0'; //将格子障碍物情况填入矩阵
    }
  }
  int ans = 0; //初始化所求的最大距离
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      memset(d, 0x3f, sizeof(d)); //初始化或重置d中个元素为无穷大
      memset(v, 0, sizeof(v));  //重置v中所有元素为0，即各个格子都曾被访问
      dfs(i, j, a[i][j]); //进行深度优先搜索DFS
      for(int x = 1; x <= n; x++) {
        for(int y = 1; y <= m; y++) {
          if(d[x][y] <= t) { 
            ans = max(ans, (x-i)*(x-i)+(y-j)*(y-j));
            /*如果要使搜索的坐标与起点坐标相互连通所需移除的障碍物的数量不超过t
            (由dfs函数定义可知即d[x][y]被修改过)，且该点与起点的距离大于此前所记录过
            的最大距离，则更新最大距离*/

          } 
        }
      }
    }
  }
  cout.precision(6);
  cout << fixed << sqrt(ans) << endl;
}