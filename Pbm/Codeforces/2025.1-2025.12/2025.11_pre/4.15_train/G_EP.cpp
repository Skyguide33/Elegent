#include <bits/stdc++.h>
using namespace std;

int main() {
    int test_cases; cin >> test_cases;
    while(test_cases--) {
        string s, t; cin >> s >> t;
    	int idx = 0;
    
    	for(int i = 0; i < (int)s.size(); ++i) {
    		if(s[i] == '?') {
    			if(idx < (int)t.size()) s[i] = t[idx++];
    			else s[i] = 'a';
    		} else if(s[i] == t[idx]) ++idx;
    	}
    	if(idx >= t.size()) cout << "YES\n" << s << "\n";
    	else cout << "NO\n";
    }
}