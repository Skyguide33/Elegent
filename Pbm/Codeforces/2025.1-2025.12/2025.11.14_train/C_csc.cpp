//2025/11/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl '\n'

void solve() {
    int n;
    cin>>n;
    vector<ll>a(n+2),sum(n+2),dp(n+2);
    for(int i=1;i<=n;i++){
      cin>>a[i];
    }
    for(int i=n;i>=1;i--){
      sum[i]=sum[i+1]+a[i];
    }
    priority_queue<pair<ll,ll>>pq;
    ll ans=0;
    for(int i=1;i<=n;i++){
      ll op=(i+1)*i+sum[i+1];
      pq.push({op,i});
    }
    ll tp=0;
    for(int i=1;i<=n;i++){
       while(pq.top().second<i)pq.pop();
       ans=max(ans,pq.top().first-tp);
       tp+=2*i-a[i];
    }
    cout<<ans<<endl;
    
}

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}