//2025/9/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll MOD = 10000;

struct edge { int to, w; };
vector<edge> e[10005];
int road[10005], cnt[10005], in[10005];

void dfs(int now) {
  for(auto &x: e[now]) {
    --in[x.to];
    cnt[x.to] = (cnt[x.to]+cnt[now])%MOD;
    road[x.to] = (road[x.to]+road[now]+cnt[now]*x.w)%MOD;
    if(!in[x.to]) dfs(x.to);
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m, src, des, t0; cin >> n >> m >> src >> des >> t0;
  for(int i = 1; i <= m; ++i) {
    int x, y, t; cin >> x >> y >> t;
    e[x].push_back({y, t});
    ++in[y];
  }
  cnt[src] = 1;
  dfs(src);
  int ans = (road[des]+(cnt[des]+MOD-1)*t0)%MOD;
  cout << ans << endl;
  return 0;
}