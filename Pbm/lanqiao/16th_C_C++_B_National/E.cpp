//2026/6/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
	int a, b, c; cin >> a >> b >> c;
	int maxab = max(a, b), minab = min(a, b);
	int maxc = minab+min(minab+1, maxab)-1;
	// cout << maxc << endl;
	if(a == 0 || b == 0) {
		if(c == 0) {
			if(a == 0) {
				for(int i = 1; i <= b; ++i) {
					cout << 'Q';
				}
			} else {
				for(int i = 1; i <= a; ++i) {
					cout << 'L';
				}
			}
		} else cout << -1;
	} else if(c == 0 || c > maxc) cout << -1;
	else {
		if(c == maxc) {
			a -= minab; b -= minab;
			if(a >= b) {
				while(a > 1) {
					cout << 'L';
					--a;
				}
			} else {
				cout << 'Q';
				--b;
			}
			for(int i = 1; i <= minab; ++i) cout << "LQ";
			if(a) cout << 'L';
			else {
				while(b--) cout << 'Q';
			}
		} else {
			if(c%2 == 0) {
				while(a > c/2) {
					cout << 'L';
					--a;
				}
				while(a > 1) {
					cout << "QL";
					--a; --b;
				}
				while(b--) cout << 'Q';
				cout << 'L';
			} else {
				while(a > c/2) {
					cout << 'L';
					--a;
				}
				while(a--) {
					cout << "QL";
					--b;
				}
				while(b--) cout << 'Q';
			}
		}
	}
	cout << endl;
  return 0;
}

