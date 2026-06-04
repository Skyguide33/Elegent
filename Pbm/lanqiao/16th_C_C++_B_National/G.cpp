//2026/6/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll a[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
	int ans = 0, n; cin >> n >> a[1];
	for(int i = 2; i <= n; ++i) {
		cin >> a[i];
		while(a[i] < a[i-1]) {
			a[i] <<= 1;
			++ans;
		}
		// cout << a[i] << ' ';
	}
	// cout << endl;
	cout << ans << endl;
  return 0;
}

