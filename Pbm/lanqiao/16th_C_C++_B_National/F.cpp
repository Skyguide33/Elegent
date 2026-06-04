//2026/6/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll dp[18][10];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
	for(int i = 0; i < 10; ++i) dp[1][i] = 1;
	for(int i = 2; i <= 18; ++i) {
		for(int j = 0; j < 10; ++j) {
			for(int k = 0; k < 10; ++k) {
				if((j+k)%2) {
					dp[i][j] += dp[i-1][k];
				}
			}
		}
	}
	ll n; cin >> n;
	string ans;
	bool flag = 1;
	for(int i = 2; i <= 18 && flag; ++i) {
		for(int j = 1; j < 10 && flag; ++j) {
			if(dp[i][j] < n) n -= dp[i][j];
			else {
				ans += '0'+j;
				int pre = j;
				for(int k = i-1; k >= 1; --k) {
					for(int l = 0; l < 10; ++l) {
						if((l+pre)%2) {
							if(dp[k][l] < n) n -= dp[k][l];
							else {
								ans += '0'+l;
								pre = l;
								break;
							}
						}
					}
				}
				flag = 0;
			}
		}
	}
	cout << ans << endl;
  return 0;
}

