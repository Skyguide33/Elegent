//2026/6/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 1000000007

ll cnt0[300005], cnt1[300005],dp[300005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cnt0[1] = cnt1[2] = 1;
  for(int i = 3; i <= 300000; ++i) {
  	cnt0[i] = (cnt0[i-1]+cnt0[i-2])%MOD;
  	cnt1[i] = (cnt1[i-1]+cnt1[i-2])%MOD;
	}
	for(int i = 3; i <= 300000; ++i) {
		dp[i] = (dp[i-1]+dp[i-2]+cnt0[i-1]*cnt1[i-2])%MOD;
	}
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		cout << dp[n] << endl;
	}
  return 0;
}

