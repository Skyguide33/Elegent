//2026/6/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

/*
12
6 1
6 2
6 3
6 4
6 5
6 6
6 7
6 8
6 9
6 10
6 11
6 12
*/

void solve() {
	int n, k; cin >> n >> k;
	k = (n+1-k%n);
	if(k == n+1) k = 1;
	// cout << "k=" << k << endl;
	if(n%2 == 0) {
		if(k%2 == 0) cout << -1 << endl;
		else cout << k/2 << endl;
	} else {
		if(k%2 == 0) cout << (n+k)/2 << endl;
		else cout << k/2 << endl;
	}
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
	int T; cin >> T;
	while(T--) solve();
  return 0;
}

