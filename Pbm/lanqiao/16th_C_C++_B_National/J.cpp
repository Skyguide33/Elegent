//2026/6/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 998244353

int a[30][30];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m, k; cin >> n >> m >> k;
	while(k--) {
		int x, y, c; cin >> x >> y >> c;
		a[x][y] = c-2;
	}
	int ans = 0, num = pow(2, (n*m));
	for(int i = 0; i < num; ++i) {
		int tt = i;
		bool flag = 1;
		for(int j = 1; j <= n && flag; ++j) {
			for(int k = 1; k <= m; ++k) {
				int c = tt&1;
				tt >>= 1;
				if(a[j][k] < 0 && a[j][k]+2 != c) {
					flag = 0;
					break; 
				}
			} 
		}
		if(flag) {
			if(n == 1 || m == 1) ++ans;
			else {
				for(int i = 1; i <= n; ++i) {
					for(int j = 1; j <= m; ++j) cout << (a[i][j]+2)%2;
					cout << endl;
				}
				bool flag2 = 1;
				for(int j = 1; j <= n && flag2; ++j) {
					for(int k = 1; k < m; ++k) {
						if(j < n && (a[j][k]-a[j][k+1])%2 == 0 && ((a[j][k]-a[j+1][k])%2 == 0 || (a[j][k]-a[j+1][k+1])%2 == 0) && (a[j+1][k]-a[j+1][k+1])%2 == 1) {
							flag2 = 0;
							break;
						} else if(j > 1 && (a[j][k]-a[j][k+1])%2 == 0 && ((a[j][k]-a[j-1][k])%2 == 0 || (a[j][k]-a[j-1][k+1])%2 == 0) && (a[j-1][k]-a[j-1][k+1])%2 == 1) {
							flag2 = 0;
							break;
						}
					}
				}
				ans += flag2;
			}
		}
	}
	cout << ans << endl;
  return 0;
}

