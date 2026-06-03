//2025/12/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ls p<<1
#define rs p<<1|1
#define N 50005

int tr[N<<2];

void update(int x, int p, int pl, int pr, int d) {
  tr[p] = max(tr[p], d);
  if(pl != pr) {
    int mid = (pl+pr)>>1;
    if(x <= mid) update(x, ls, pl, mid, d);
    else update(x, rs, mid+1, pr, d);
  }
}

int query(int L, int R, int p, int pl, int pr) {
  if(L <= pl && pr <= R) return tr[p];
  int mid = (pl+pr)>>1, res = 0;
  if(L <= mid) res = query(L, R, ls, pl, mid);
  if(R > mid) res = max(res, query(L, R, rs, mid+1, pr));
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  map<int, int> mp, mpy;
  vector<pair<int, int>> a(n+1);
  for(int i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second;
    mp[a[i].first] = 0;
  }
  int cnt = 0; 
  for(auto &[x, y]: mp) y = ++cnt;
  mp[INT_MAX>>1] = cnt+1;
  mp[INT_MIN>>1] = 0;
  for(int i = 1; i <= n; ++i) {
    mpy[mp[a[i].first]] = a[i].second;
    update(mp[a[i].first], 1, 1, cnt, a[i].second);
  }
  int m; cin >> m;
  while(m--) {
    int x, y; cin >> y >> x;
    if(mp.count(x)) {
      int l = mp.upper_bound(y)->second, r = mp[x]-1, mid = 0;
      if(l <= r) mid = query(l, r, 1, 1, cnt);
      if(mp.count(y)) {
        if(mpy[mp[x]] <= mpy[mp[y]] && mpy[mp[x]] > mid) {
          if(x-y == mp[x]-mp[y]) cout << "true" << endl;
          else cout << "maybe" << endl;
        } else cout << "false" << endl;
      } else {
        if(mpy[mp[x]] > mid) cout << "maybe" << endl;
        else cout << "false" << endl;
      }
    } else {
      if(mp.count(y)) {
        int l = mp.upper_bound(y)->second, r = mp.upper_bound(x)->second-1, mid = 0;
        if(l <= r) mid = query(l, r, 1, 1, cnt);
        if(mpy[mp[y]] > mid) cout << "maybe" << endl;
        else cout << "false" << endl;
      } else cout << "maybe" << endl;
    }
  }
  return 0;
}