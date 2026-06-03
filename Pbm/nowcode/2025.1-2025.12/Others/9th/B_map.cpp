//2025/8/12
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;

ll yr[100005][2], md[100005], n29[100005];

ll month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool is_lunar(ll year) {
  if((year%4 == 0 && year%100) || year%400 == 0) return 1;
  return 0;
}

void solve() {
  ll n; cin >> n;
  string s; cin >> s;
  if(n < 8) {
    cout << 0 << endl;
    return;
  }
  map<ll, ll> m1, m2, m3;
  for(int i = 0; i < n; ++i) {
    ll t = s[i]-'0';
    for(auto& [x, y]: m3) {
      ll t4 = x*10+t;
      if(t4) {
        if(is_lunar(t4)) yr[i][1] = (yr[i][1]+y)%MOD;
        else yr[i][0] = (yr[i][0]+y)%MOD;
      }
    }
    for(auto& [x, y]: m2) {
      ll t3 = x*10+t;
      if(m3.count(t3)) m3[t3] = (m3[t3]+y)%MOD;
      else m3[t3] = y;
    }
    for(auto& [x, y]: m1) {
      ll t2 = x*10+t;
      if(m2.count(t2)) m2[t2] = (m2[t2]+y)%MOD;
      else m2[t2] = y;
    }
    if(m1.count(t)) ++m1[t];
    else m1[t] = 1;
  }
  set<ll> date;
  for(int i = 1; i <= 12; ++i) {
    for(ll j = 1; j <= month[i]; ++j) {
      date.insert(i*100+j);
    }
  }
  
  map<ll,ll> mn1, mn2, mn3;
  mn3[229] = 0;
  for(auto& x: date) {
    mn3[x%1000] = 0;
  }
  for(auto& [x, y]: mn3) {
    mn2[x%100] = 0;
  }
  for(int i = n-1; i >= 0; --i) {
    ll t = s[i]-'0';
    md[i] = md[i+1];
    n29[i] = n29[i+1];
    if(t == 0) n29[i] = (n29[i]+mn3[229])%MOD;
    for(auto& [x, y]: mn3) {
      ll t4 = t*1000+x;
      if(date.count(t4)) md[i] = (md[i]+y)%MOD;
    }
    for(auto& [x, y]: mn2) {
      ll t3 = t*100+x;
      if(mn3.count(t3)) mn3[t3] = (mn3[t3]+y)%MOD;
    }
    for(auto& [x, y]: mn1) {
      ll t2 = t*10+x;
      if(mn2.count(t2)) mn2[t2] = (mn2[t2]+y)%MOD;
    }
    if(mn1.count(t)) ++mn1[t];
    else mn1[t] = 1;
  }

  // cout << "yr[i][0]=";
  // for(ll i = 0; i < n; ++i) {
  //   cout << yr[i][0] << ' ';
  // }
  // cout << endl;
  // cout << "yr[i][1]=";
  // for(ll i = 0; i < n; ++i) {
  //   cout << yr[i][1] << ' ';
  // }
  // cout << endl;
  // cout << "md[i]=";
  // for(ll i = 0; i < n; ++i) {
  //   cout << md[i] << ' ';
  // }
  // cout << endl;
  
  ll ans = 0;
  for(int i = 3; i < n-4; ++i) {
    ans = (ans+((yr[i][0]+yr[i][1])*md[i+1]+yr[i][1]*n29[i+1])%MOD)%MOD;
    // cout << "t1=" << t1 << ", t2=" << t2 << ' ';
  }
  // cout << endl;
  // cout << "m1.size()=" << m1.size() << ", m2.size()=" << m2.size() << ", m3.size()=" << m3.size() << endl;
  // cout << "mn1.size()=" << mn1.size() << ", mn2.size()=" << mn2.size() << ", mn3.size()=" << mn3.size() << endl;
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll T = 1; //cin >> T;
  while(T--) solve();
  return 0;
}