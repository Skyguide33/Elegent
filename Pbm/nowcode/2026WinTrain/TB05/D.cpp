//2026/2/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 1000000007

void method1() {
  int n; cin >> n;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
  for(int i = 1; i <= n; ++i) {
    int c, w; cin >> c >> w;
    q.push({w, c});
  }
  ll ans = 0;
  while(!q.empty()) {
    auto [lw, lc] = q.top(); q.pop();
    if(lc > 1) {
      ll new_c = lc/2;
      ll new_w = lw*2;
      ans = (ans+new_c*new_w%MOD)%MOD;
      if(lc%2) q.push({lw, 1});
      q.push({new_w, new_c});
    } else if(!q.empty()) {
      auto [rw, rc] = q.top(); q.pop();
      ll new_c = 1;
      ll new_w = lw+rw;
      ans = (ans+new_c*new_w%MOD)%MOD;
      if(--rc) q.push({rw, rc});
      q.push({new_w, new_c});
    }
  }
  cout << ans << endl;
}

void method2() {
  int n; cin >> n;
  map<ll, ll> mp;
  for(int i = 1; i <= n; ++i) {
    int c, w; cin >> c >> w;
    mp[w] += c;
  }
  ll ans = 0;
  while(!mp.empty()) {
    auto it = mp.begin();
    auto [lw, lc] = *it; mp.erase(it);
    if(lc > 1) {
      ll new_w = lw*2, new_c = lc/2;
      if(lc%2) mp[lw] = 1;
      mp[new_w] +=  new_c;
      ans = (ans+new_w*new_c)%MOD;
    } else if(!mp.empty()) {
      it = mp.begin();
      auto &[rw, rc] = *it;
      ll new_w = lw+rw;
      if(--rc == 0) mp.erase(it);
      mp[new_w] += 1;
      ans = (ans+new_w)%MOD;
    }
  }
  cout << ans << endl;
}

void method3() {
  int n; cin >> n;
  vector<pair<ll, ll>> a(n+1);
  for(int i = 1; i <= n; ++i) {
    cin >> a[i].second >> a[i].first;
  }
  sort(a.begin()+1, a.end());
  int idx = 1;
  queue<pair<ll, ll>> b;
  ll ans = 0;
  while(idx <= n || !b.empty()) {
    ll lw, lc;
    if(b.empty() || (idx <= n && a[idx] < b.front())) {
      lw = a[idx].first, lc = a[idx].second;
      if(lc > 1 && lc%2) a[idx].second = 1;
      else ++idx;
    } else {
      lw = b.front().first, lc = b.front().second;
      if(lc > 1 && lc%2) b.front().second = 1;
      else b.pop();
    }
    if(lc > 1) {
      ll new_w = lw*2, new_c = lc/2;
      b.push({new_w, new_c});
      ans = (ans+new_w*new_c)%MOD;
    } else if(idx <= n || !b.empty()) {
      ll rw, rc, new_w;
      if(b.empty() || (idx <= n && a[idx] < b.front())) {
        rw = a[idx].first, rc = --a[idx].second;
        if(rc == 0) ++idx;
      } else {
        rw = b.front().first, rc = --b.front().second;
        if(rc == 0) b.pop();
      }
      new_w = lw+rw;
      b.push({new_w, 1});
      ans = (ans+new_w)%MOD;
    }
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  method3();
  return 0;
}