//2025/8/12
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;

ll yr[100005][2], md[100005], n29[100005];

ll month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

ll m1[10], m2[100], m3[1000], mn1[10], mn2[100], mn3[1000];

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
  for(int i = 0; i < n; ++i) {
    int t = s[i]-'0';
    for(int j = 0; j < 1000; ++j) {
      ll t4 = j*10+t;
      if(t4) {
        if(is_lunar(t4)) yr[i][1] = (yr[i][1]+m3[j])%MOD;
        else yr[i][0] = (yr[i][0]+m3[j])%MOD;
      }
    }
    for(int j = 0; j < 100; ++j) {
      ll t3 = j*10+t;
      m3[t3] = (m3[t3]+m2[j])%MOD;
    }
    for(int j = 0; j < 10; ++j) {
      ll t2 = j*10+t;
      m2[t2] = (m2[t2]+m1[j])%MOD;
    }
    ++m1[t];
  }
  set<ll> date;
  for(ll i = 1; i <= 12; ++i) {
    for(ll j = 1; j <= month[i]; ++j) {
      date.insert(i*100+j);
    }
  }
  for(ll i = n-1; i >= 0; --i) {
    ll t = s[i]-'0';
    md[i] = md[i+1];
    n29[i] = n29[i+1];
    if(t == 0) n29[i] = (mn3[229]+n29[i])%MOD;
    for(int j = 0; j < 1000; ++j) {
      ll t4 = t*1000+j;
      if(date.count(t4)) md[i] = (md[i]+mn3[j])%MOD;
    }
    for(int j = 0; j < 100; ++j) {
      ll t3 = t*100+j;
      mn3[t3] = (mn3[t3]+mn2[j])%MOD;
    }
    for(int j = 0; j < 10; ++j) {
      ll t2 = t*10+j;
      mn2[t2] = (mn2[t2]+mn1[j])%MOD;
    }
    ++mn1[t];
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
  for(ll i = 3; i < n-4; ++i) {
    ll t1 = ((yr[i][0]+yr[i][1])*md[i+1])%MOD;
    ll t2 = (yr[i][1]*n29[i+1])%MOD;
    ans = (ans+t1+t2)%MOD;
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