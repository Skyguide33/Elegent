//2025/10/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

char s[1000005];
int Next[1000005];

int main() {
	cin.tie(0) -> sync_with_stdio(0);
	int n; scanf("%d\n", &n);
	for(int i = 1; i <= n; ++i) s[i] = getchar(); 
	for(int i = 2, j = 0; i <= n; ++i) {
		while(j && s[i] != s[j+1]) j = Next[j];
		if(s[i] == s[j+1]) ++j;
		Next[i] = j;
	}
	ll ans = 0; 
	for(int i = 2, j = 2; i <= n; ++i, j = i) {
		while(Next[j]) j = Next[j];
		if(Next[i]) Next[i] = j;
		ans += i-j;
	}
	printf("%lld\n", ans);
	return 0;
}