//2026/2/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * longest common subsequence
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */
    string LCS(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1)), p(n+1, vector<int>(m+1));
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1]+1;
                    p[i][j] = 0;
                } else if(dp[i-1][j] > dp[i][j-1]) {
                    dp[i][j] = dp[i-1][j];
                    p[i][j] = 1;
                } else {
                    dp[i][j] = dp[i][j-1];
                    p[i][j] = 2;
                }
            }
        }
        string res;
        int i = n, j = m;
        while(i && j) {
            if(p[i][j] == 0) {
                res += s1[i-1];
                --i; --j;
            } else if(p[i][j] == 1) --i;
            else --j;
        }
        if(res.empty()) return "-1";
        reverse(res.begin(), res.end());
        return res;
    }
};