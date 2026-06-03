//2025/4/18 rewrite
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  double d[16][16], x[16], y[16], F[16][33000], ans = 1e18;
  memset(F, 127, sizeof(F));
  int N; cin >> N;
  for(int i = 1; i <= N; i++) cin >> x[i] >> y[i];
  for(int i = 0; i < N; i++) 
    for(int j = i+1; j <= N; j++) d[i][j] = d[j][i] = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
  for(int i = 1; i <= N; i++) F[i][(1<<i-1)] = d[0][i];
  for(int k = 1; k < (1<<N); k++) 
    for(int i = 1; i <= N; i++)
      if(k & (1<<(i-1)))
        for(int j = 1; j <= N; j++)
          if(i != j && k & (1<<(j-1))) F[i][k] = min(F[i][k],F[j][k-(1<<(i-1))]+d[i][j]);       
  for(int i = 1; i <= N; i++) ans = min(ans,F[i][(1<<N)-1]);
  cout.precision(2);
  cout << fixed << ans << endl;
  return 0;
}