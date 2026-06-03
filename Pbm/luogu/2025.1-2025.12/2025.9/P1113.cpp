//2025/9/27
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 10005;

int n;

struct edge{ int to, w; };
struct node{ 
  int id, dis;
  bool operator < (const node &other) const { return dis < other.dis; }
};

vector<edge>e[N];

int dist[N], pre[N];
bool final[N];

void dijkstra(int s) {
  memset(dist, 0, sizeof(dist));
  priority_queue<node> q;
  q.push({s, dist[s]});
  while(!q.empty()) {
    node now = q.top(); q.pop();
    // if(final[now.id]) continue;
    // final[now.id] = 1;
    for(size_t i = 0; i < e[now.id].size(); ++i) {
      edge next = e[now.id][i];
      // if(final[next.to]) continue;
      int dis = dist[now.id] + next.w;
      if(dist[next.to] < dis) {
        dist[next.to] = dis;
        pre[next.to] = now.id;
        q.push({next.to, dist[next.to]});
      }
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i <= n; ++i) {
    int tp, ti; cin >> tp >> ti;
    cin >> tp; 
    if(!tp) e[0].push_back({i, ti});
    while(tp) {
      e[tp].push_back({i, ti});
      cin >> tp;
    }
  }
  dijkstra(0);
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    ans = max(ans, dist[i]);
  }
  // cout << endl;
  cout << ans << endl;
  return 0;
}