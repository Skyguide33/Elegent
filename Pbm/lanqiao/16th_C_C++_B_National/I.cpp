//2026/6/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int rpos[100005][26];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
	string s; cin >> s;
	int n = s.length();
	s = ' '+s;
	for(int i = n; i >= 1; --i) {
		for(int j = 0; j < 26; ++j) {
			rpos[i][j] = rpos[i+1][j];
			if(s[i] == 'a'+j) rpos[i][j] = i;
		}
	}
	int m; cin >> m;
	while(m--) {
		int la, ra, lb, rb; cin >> la >> ra >> lb >> rb;
		vector<pair<int, char>> p1(26), p2(26);
		for(int i = 0; i < 26; ++i) {
			if(rpos[la][i] <= ra) {
				p1[i] = {rpos[la][i], 'a'+i};
			}
			if(rpos[lb][i] <= rb) {
				p2[i] = {rpos[lb][i], 'a'+i};
			}
		}
		sort(p1.begin(), p1.end());
		sort(p2.begin(), p2.end());
		string s1, s2;
		for(int i = 0; i < 26; ++i) {
			if(p1[i].first != 0) s1 += p1[i].second;
			if(p2[i].first != 0) s2 += p2[i].second;
		}
		// cout << "s1=" << s1 <<  ",S2=" << s2 << endl;
		int len1 = s1.length(), len2 = s2.length();
		if(len1 > len2) swap(len1, len2);
		int ans = len2-len1;
		for(int i = 0; i < len1; ++i) {
			if(s1[i] != s2[i]) ++ans;
		}
		cout << ans << endl;
	}
  return 0;
}

