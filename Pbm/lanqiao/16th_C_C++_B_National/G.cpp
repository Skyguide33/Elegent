//2026/6/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll a[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
	ll ans = 0, n; cin >> n >> a[1];
	int b = 0;
	for(int i = 2; i <= n; ++i) {
		cin >> a[i];
		while(a[i] < a[i-1]) {
			a[i] <<= 1;
			++ans;
		}
		ans += b;
		while(a[i] >= 1e10) {
			a[i] >>= 1;
			++b;
		}
		cout << a[i] << ' ';
	}
	cout << endl;
	cout << ans << endl;
  return 0;
}

