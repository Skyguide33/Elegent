//2025/10/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 200005
#define INF 1000000000


struct Node {
  ll ls, rs, num;
  ll sum;
} t[N<<5];
ll rt, cnt, a[N];

void update(ll pos, ll &p, ll pl, ll pr, ll d) {
  if(!p) p = ++cnt;
  t[p].num += d;
  t[p].sum += pos*d;
  if(pl == pr) return;
  ll mid = (pl+pr)>>1;
  if(pos <= mid) update(pos, t[p].ls, pl, mid, d);
  else update(pos, t[p].rs, mid+1, pr, d);
}

ll query(ll sum, ll p, ll pl, ll pr) {
  ll mid = (pl+pr)>>1;
  if(pl == pr) return (sum <= 0? 0: (sum+pl-1)/pl);
  if(t[t[p].rs].sum >= sum) return query(sum, t[p].rs, mid+1, pr);
  else return query(sum-t[t[p].rs].sum, t[p].ls, pl, mid)+t[t[p].rs].num;
}
 
int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll n, q, cnt_p = 0; cin >> n >> q;
  ll sum = 0;
  for(ll i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
    if(a[i] > 0) {
      update(a[i], rt, 1, INF, 1); ++cnt_p;
    }
  }
  while(q--) {
    ll x, v; cin >> x >> v;
    sum += v-a[x];
    if(a[x] > 0) update(a[x], rt, 1, INF, -1), --cnt_p;
    if(v > 0) update(v, rt, 1, INF, 1), ++cnt_p;
    a[x] = v;
    cout << cnt_p-query(sum, rt, 1, INF)+1 << endl;
  }
  return 0; 
}