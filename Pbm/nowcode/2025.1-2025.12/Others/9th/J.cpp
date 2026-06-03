#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define PII pair<ll, ll>
#define int ll
// #define endl '\n'
// #define lll __int128
#define yes cout << "Yes\n"
#define no cout << "No\n"

const int inf = 1e9 + 10;
const int N = 2e5 + 5;
// const int P = 998244353;
const int P = 1e9 + 7;



void solve() {
	int n; cin >> n;
  string s; 
  getline(cin, s);
	cout << n << " nya\n";
	for (int i = 1; i <= n;i++) {
		getline(cin, s);
		cout << s << " nya\n";
	}
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int TT = 1;
	// cin >> TT;
	while (TT--)
		solve();
	return 0;
}
