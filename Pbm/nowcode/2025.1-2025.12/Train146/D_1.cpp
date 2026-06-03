//2025/11/22 补题
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
 
char a[1005][1005], s[100005];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 }; // 定义方向 U:0 R:1 D:2 L:3.
// nxt[i][j]存储指令序列s(下标从0开始)中第(i-1+len)%len个位置后第一次出现方向为j的指令的位置(nxt[i][j]可能小于i).
// 使用fp数组辅助构建nxt数组, 具体见下面代码.
int nxt[100005][4], fp[4], ma[1005][1005];
ll tt[1005][1005];
// ma[i][j]和tt[i][j]分别存储从起点(1, 1)到(i, j)处所需的最小手动操作次数和对应的最短时间, 初始时均设为无穷大.
 
struct Node { 
  int x, y; 
  bool operator < (const Node &B) const {
    if(ma[x][y] == ma[B.x][B.y]) return tt[x][y] > tt[B.x][B.y];
    return ma[x][y] > ma[B.x][B.y];
  }
};
 
int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  cin >> s;
  int len = strlen(s);
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) cin >> a[i][j];
  }
 
  // 构建nxt数组
  memset(nxt, -1, sizeof(nxt)); 
  memset(fp, -1, sizeof(fp));
  for(int i = len-1; i >= 0; --i) {
    if(s[i] == 'U') nxt[i][0] = i, fp[0] = i;
    else if(s[i] == 'R') nxt[i][1] = i, fp[1] = i;
    else if(s[i] == 'D') nxt[i][2] = i, fp[2] = i;
    else nxt[i][3] = i, fp[3] = i;
  }
  for(int i = 0; i < 4; ++i) {
    if(nxt[len-1][i] == -1) nxt[len-1][i] = fp[i];
  }
  for(int i = len-2; i >= 0; --i) {
    for(int j = 0; j < 4; ++j) {
      if(nxt[i][j] == -1) nxt[i][j] = nxt[i+1][j];
    }
  }
  
  // 使用Dijkstra算法进行搜索
  memset(ma, 0x3f, sizeof(ma)); 
  memset(tt, 0x3f, sizeof(tt));
  priority_queue<Node> q;
  ma[1][1] = tt[1][1] = 0;
  q.push({1, 1});
  while(!q.empty()) {
    auto [x, y] = q.top(); q.pop();
    ll tme = tt[x][y], mal = ma[x][y];
    for(int i = 0; i < 4; ++i) {
      int nx = x+dx[i], ny = y+dy[i];
      if(nx < 1 || ny < 1 || nx > n || ny > m || a[nx][ny] == '#') continue; // 剪掉不合法的相邻节点
      // tme%len意为当前时刻所对应的指令序号.
      // (nxt[tme%len][i] == -1)意为指令序列s中不存在方向为i的指令, 要想移动到(nx, ny)必须要靠手动.
      if(nxt[tme%len][i] == -1) {
        ll nma = mal+1, ntt = tme+1;
        if(nma < ma[nx][ny] || (nma == ma[nx][ny] && ntt < tt[nx][ny])) {
          ma[nx][ny] = nma; tt[nx][ny] = ntt;
          q.push({nx, ny});
        }
      } else {
        // ntt意为(x, y)移动到(nx, ny)后的时刻, nidx意为那个时刻对应的指令序号.
        int nidx = (nxt[tme%len][i]+1)%len;
        // 注意: 若下一行写成"ll ntt = tme+(nidx-tme%len+len)%len"可能会导致(ntt == tme).
        ll ntt = tme+(nidx-tme%len+len-1)%len+1;
        if(mal < ma[nx][ny] || (mal == ma[nx][ny] && ntt < tt[nx][ny])) {
          ma[nx][ny] = mal;
          tt[nx][ny] = ntt;
          q.push({nx, ny});
        }
      }
    }
  }
  cout << ma[n][m] << ' ' << tt[n][m] << endl;
  return 0;
}