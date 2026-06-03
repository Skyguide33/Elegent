//2025/10/13
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 100005
#define K 2

struct Point { int dim[K]; } q[N], t[N];
int now;
ll ans;

bool cmp(Point a, Point b) { return a.dim[now] < b.dim[now]; }

ll square(int x) { return (ll)x*x; }

ll dis(Point a, Point b) {
  return square(a.dim[0]-b.dim[0])+square(a.dim[1]-b.dim[1]);
}

void build(int L, int R, int dep) {
  if(L >= R) return;
  int mid = (L+R)>>1;
  now = dep%K;
  nth_element(t+L, t+mid, t+R, cmp);
  ++dep;
  build(L, mid, dep);
  build(mid+1, R, dep);
}

void query(int L, int R, int dep, Point p) {
  if(L >= R) return;
  int mid = (L+R)>>1;
  int d = dep%K;
  ll mindis = dis(t[mid], p);
  if(ans == 0 || (mindis != 0 && ans > mindis)) ans = mindis;
  ++dep;
  if(p.dim[d] > t[mid].dim[d]) {
    query(mid+1, R, dep, p);
    if(ans > square(t[mid].dim[d]-p.dim[d])) query(L, mid, dep, p);
  } else {
    query(L, mid, dep, p);
    if(ans > square(t[mid].dim[d]-p.dim[d])) query(mid+1, R, dep, p);
  }
}

void solve() {
  int n; cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> q[i].dim[0] >> q[i].dim[1]; t[i] = q[i];
  }
  build(0, n, 0);
  for(int i = 0; i < n; ++i) {
    ans = 0;
    query(0, n, 0, q[i]);
    cout << ans << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}