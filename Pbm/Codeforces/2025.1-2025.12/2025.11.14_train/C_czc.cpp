//2025/11/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n;
    cin>>n;
    vector<ll>a(n+1),sum(n+1),dp(n+1);
    for(int i=1;i<=n;i++){
      cin>>a[i];
      sum[i]=sum[i-1]+a[i];
    }
    //(L+R)*(R-L+1) - sum[L-1]+sum[R]; R*R+R-L*L+L
    ll ans= 0;
    for(long long i=1;i<=n;i++){
      dp[i]=max(dp[i-1],i-i*i+sum[i-1]);
      ans = max(ans,dp[i]+i*i+i-sum[i]);
    }
    cout<<ans+sum[n]<<'\n';
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}