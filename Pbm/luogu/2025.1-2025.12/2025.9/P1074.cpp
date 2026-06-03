//2025/9/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[11][11], s[11][11], w[10][10], vr[11][10], vc[11][10], v[10][10], seqr[10], seqp[100][2], cnt, ans;

bool cmp(int &a, int &b) { return vr[a][0] < vr[b][0]; }

void dfs(int now, int total) {
  if(now == cnt) {
    ans = max(ans, total);
    return;
  }
  for(int i = 1; i <= 9; ++i) {
    int &x = seqp[now][0], &y = seqp[now][1];
    if(vr[x][i] || vc[y][i] || v[w[x][y]][i]) continue;
    vr[x][i] = 1; vc[y][i] = 1; v[w[x][y]][i] = 1;
    dfs(now+1, total+i*s[x][y]);
    vr[x][i] = 0; vc[y][i] = 0; v[w[x][y]][i] = 0;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  for(int i = 1; i <= 9; ++i) {
    seqr[i] = i;
    for(int j = 1; j <= 9; ++j) {
      w[i][j] = (i-1)/3*3+(j+2)/3;
      s[i][j] = 10-max(abs(i-5), abs(j-5));
      cin >> a[i][j]; 
      ++vr[i][a[i][j]];
      vc[j][a[i][j]] = 1;
      v[w[i][j]][a[i][j]] = 1;
      ans += a[i][j]*s[i][j];
    }
  }
  sort(seqr+1, seqr+10, cmp);
  for(int i = 1; i <= 9; ++i) {
    for(int j = 1; j <= 9; ++j) {
      if(a[seqr[i]][j] == 0) {
        seqp[cnt][0] = seqr[i]; seqp[cnt++][1] = j;
      }
    }
  }
  dfs(0, ans);
  cout << ans << endl;
  return 0; 
}