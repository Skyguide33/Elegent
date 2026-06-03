//2025/5/7
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct edge{ ll to, w; } ;
struct node{ 
  ll id, dis;
  bool operator < (const node& other) const { return dis > other.dis; }
};

vector<edge> e[100005];

ll n, dist[10005], f[10005], fs[10005];
bool final[100005];

ll dijkstra(ll maxv) {
  for(ll i = 1; i <= n; ++i) dist[i] = 1e13;
  // memset(dist, 127, sizeof(dist));
  memset(final, 0, sizeof(final));
  priority_queue<node> q;
  dist[1] = 0; q.push({1, 0});
  while(!q.empty()) {
    node now = q.top(); q.pop();
    if(final[now.id]) continue;
    else final[now.id] = 1;
    for(ll i = 0; i < e[now.id].size(); ++i) {
      edge next = e[now.id][i];
      if(final[next.to] || f[next.to] > maxv) continue;
      ll dis = dist[now.id] + next.w;
      if(dis < dist[next.to]) {
        dist[next.to] = dis;
        q.push({next.to, dist[next.to]});
      }
    }
  }
  return dist[n];
}

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll m, b; cin >> n >> m >> b;
  for(ll i = 1; i <= n; ++i) {
    cin >> f[i]; fs[i] = f[i]; 
  }
  while(m--) {
    ll a, b, c; cin >> a >> b >> c;
    e[a].push_back({b, c});
    e[b].push_back({a, c});
  }
  sort(fs+1, fs+n+1);
  ll l = 1, r = n+1;
  ll dis = 1e18;
  while(l < r) {
    ll mid = l + (r-l)/2;
    dis = dijkstra(fs[mid]);
    if(dis <= b) {
      r = mid;
    } else l = mid+1;
  }
  if(r <= n && dijkstra(fs[l]) <= b) cout << max(f[1], fs[l]) << endl;
  else cout << "AFK" << endl;
  return 0;
}