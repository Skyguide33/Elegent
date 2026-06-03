//2026/3/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 10007

int tr[6005][26], fail[6005], invld[6005], cnt;
int dp[101][6005];
char s[102];

void Insert() {
  int now = 0;
  for(int i = 0; s[i]; ++i) {
    int ch = s[i]-'A';
    if(!tr[now][ch]) tr[now][ch] = ++cnt;
    now = tr[now][ch];
  }
  invld[now] = 1;
}

void Build() {
  queue<int> q;
  for(int i = 0; i < 26; ++i) {
    if(tr[0][i]) q.push(tr[0][i]);
  }
  while(!q.empty()) {
    int now = q.front(); q.pop();
    for(int i = 0; i < 26; ++i) {
      if(tr[now][i]) {
        fail[tr[now][i]] = tr[fail[now]][i];
        invld[tr[now][i]] |= invld[fail[tr[now][i]]];
        q.push(tr[now][i]);
      } else tr[now][i] = tr[fail[now]][i];
    }
  }
}

int fast_power(int b, int p) {
  int res = 1;
  while(p) {
    if(p&1) res = res*b%MOD;
    b = b*b%MOD;
    p >>= 1;
  }
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  while(n--) cin >> s, Insert();
  Build();
  dp[0][0] = 1;
  for(int i = 0; i < m; ++i) {
    for(int j = 0; j <= cnt; ++j) {
      for(int k = 0; k < 26; ++k) {
        if(!invld[tr[j][k]])
        dp[i+1][tr[j][k]] = (dp[i+1][tr[j][k]]+dp[i][j])%MOD;
      }
    }
  }
  int ans = fast_power(26, m);
  for(int i = 0; i <= cnt; ++i) ans = (ans-dp[m][i]+MOD)%MOD;
  cout << ans << endl;
  return 0;
}