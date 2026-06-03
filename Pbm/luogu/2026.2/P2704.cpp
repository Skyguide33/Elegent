//2025.2.18
#include <bits/stdc++.h>
using namespace std;

int s[1<<10], num[1<<10], cnt, g[105], dp[2][1<<10][1<<10]; 

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            char ch; cin >> ch;
            g[i] <<= 1;
            if(ch == 'P') g[i] |= 1;
        }
    }
    for(int i = 0; i < (1<<m); ++i) {
        if(i&(i<<1) || i&(i<<2)) continue;
        int tt = i;
        while(tt) {
            if(tt&1) ++num[cnt];
            tt >>= 1;
        }
        s[cnt++] = i;
    }
    for(int i = 1; i <= n+2; ++i) {
        for(int a = 0; a < cnt; ++a) {
            if(i >= 3 && (s[a]&g[i-2]) != s[a]) continue;
            for(int b = 0; b < cnt; ++b) {
                if((i >= 2 && (s[b]&g[i-1]) != s[b]) || s[a]&s[b]) continue;
                for(int c = 0; c < cnt; ++c) {
                    if((s[c]&g[i]) != s[c] || s[a]&s[c] || s[b]&s[c]) continue;
                    dp[i&1][b][c] = max(dp[i&1][b][c], dp[(i-1)&1][a][b]+num[c]);
                }
            }
        }
    }
    cout << dp[(n+2)&1][0][0] << endl;
}