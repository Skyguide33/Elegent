#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int ll
#define PII pair<int, int>
// #define endl '\n'
// #define lll __int128
#define yes cout << "Yes\n"
#define no cout << "No\n"

const ll inf = 2e18 + 10;
const int N = 1e5 + 5;
// const int P = 998244353;
const int P = 1e9 + 7;

double sml = 1e-9;

void solve() {
	int n;
	cin >> n;
	int cnt = (n + 1) / 2;
	int x;
	for (int i = 1;i <= cnt;i++) {
		int u, v;
		u = i * 2 - 1;
		v = i * 2;
		if (i == cnt && (n & 1)) {
			v = i * 2 - 2;
		}
		cout << "? " << u << ' ' << v << endl;
		cout.flush();
		cin >> x;
		if (x == 1) {
			if (i == 1) {
				cout << "? " << 1 << ' ' << 3 << endl;//1
				cout.flush();
				cin >> x;
				if (x == 1) {
					cout << "? " << 1 << ' ' << 4 << endl;//2
					cout.flush();
					cin >> x;
					if (x == 1) {
						cout << "! 2" << endl;
					} else {
						cout << "! 1" << endl;
					}
					cout.flush();

				} else {
					cout << "? " << 2 << ' ' << 3 << endl;//2
					cout.flush();
					cin >> x;
					//3
					if (x == 1) {
						cout << "? " << 2 << ' ' << 4 << endl;
						cout.flush();
						cin >> x;
						cout << "! " << (x ? 2 : 1) << endl;
					} else cout << "! 1" << endl;
					cout.flush();
				}
			} else {
				cout << "? " << 1 << ' ' << u << endl;//1
				cout.flush();
				cin >> x;
				if (x == 1) {
					cout << "? " << 2 << ' ' << u << endl;//2
					cout.flush();
					cin >> x;
					cout << "! " << (x ? 2 : 1) << endl;
					cout.flush();
				} else {
					cout << "? " << 1 << ' ' << v << endl;//2
					cout.flush();
					cin >> x;
					if (x == 1) {
						cout << "? " << 2 << ' ' << v << endl;//3
						cout.flush();
						cin >> x;
						cout << "! " << (x ? 2 : 1) << endl;
					} else cout << "! 1" << endl;
					cout.flush();
				}
			}
			return;
		}
	}

}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int TT = 1;
	// per();
	cin >> TT;
	while (TT--)
		solve();
	return 0;
}