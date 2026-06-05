//2026/6/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define endl '\n'
#define MOD 1000000007
#define N 2025

ll dp[2030][2030];

int lcm(int a, int b) {
	return a*b/__gcd(a, b);
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
	for(int i = 1; i <= N; i += 2) dp[1][i] = 1;
	for(int i = 2; i <= N; ++i) {
		cout << "i=" << i << endl;
		for(int j = 1; j <= N; j += 2) {
			for(int k = 1; k <= N; k += 2) {
				if(lcm(j, k) == N) {
					dp[i][j] = (dp[i][j]+dp[i-1][k])%MOD;
				}
			}
		}
	}
	ll ans = 0;
	for(int i = 1; i <= N; i += 2) {
		ans = (ans+dp[N][i])%MOD;
	}
	cout << ans << endl;
  return 0;
}

