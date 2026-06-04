//2026/6/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 1000000007



ll fast_power(ll b, int p) {
	ll res = 1;
	while(p) {
		if(p&1) res = res*b%MOD;
		b = b*b%MOD;
		p >>= 1;
	}
	return res;
}

int ans[7] = {0, 0, 650, 1300, 50050, 67600, 2179450};

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
//  int num = fast_power(26, n);
//  int ans = 0;
//  for(int i = 0; i < num; ++i) {
//  	string s;
//  	int tt = i;
//  	for(int j = 0; j < n; ++j) {
//  		s += 'a'+tt%26;
//  		tt /= 26;
//		}
//		// cout << s << ' ';
//		string sr = s;
//		reverse(sr.begin(), sr.end());
//		if(s == sr) continue;
//		for(int i = 0; i < n; ++i) {
//			string t = s.substr(0, i)+s.substr(i+1);
//			string tr = t;
//			reverse(tr.begin(), tr.end());
//			// cout << t << ' ' << tr << endl;
//			if(t == tr) {
//				// cout << t;
//				++ans;
//				break;
//			}
//		}
//		// cout << endl;
//	}
//	cout << ans << endl;
	cout << ans[n] << endl; 
  return 0;
}

