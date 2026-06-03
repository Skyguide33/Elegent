//2025/11/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define endl '\n'

int a[7], b[7], n, m;
int sa[7], sb[7]; // 血量值
int aatk[7], batk[7]; // 各成员的进攻数量
double wa, wb, te;

void dfs(bool turn, double p) {
  int al = 0, bl = 0;
  for(int i = 0; i < n; ++i) 
    if(sa[i] > 0) ++al;
  for(int i = 0; i < m; ++i) 
    if(sb[i] > 0) ++bl;

  if(!al && !bl) { te += p; return; } 
  else if(al && !bl) { wa += p; return; } 
  else if(!al && bl) { wb += p; return; }

  if(!turn) {
    int atkm = -1, minatk = 1e9;
    for(int i = 0; i < n; ++i) {
      if(sa[i] > 0 && aatk[i] < minatk) {
        atkm = i;
        minatk = aatk[i];
      }
    }
    for(int i = 0; i < m; ++i) {
      if(sb[i] <= 0) continue;
      sb[i] -= a[atkm];
      sa[atkm] -= b[i];
      ++aatk[atkm];
      dfs(turn^1, p/bl);
      --aatk[atkm];
      sa[atkm] += b[i];
      sb[i] += a[atkm];
    }
  } else {
    int atkm = -1, minatk = 1e9;
    for(int i = 0; i < m; ++i) {
      if(sb[i] > 0 && batk[i] < minatk) {
        atkm = i;
        minatk = batk[i];
      }
    }
    for(int i = 0; i < n; ++i) {
      if(sa[i] <= 0) continue;
      sb[atkm] -= a[i];
      sa[i] -= b[atkm];
      ++batk[atkm];
      dfs(turn^1, p/al);
      --batk[atkm];
      sa[i] += b[atkm];
      sb[atkm] += a[i];
    }
  }
} 

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 0; i < n; ++i) cin >> a[i], sa[i] = a[i];
  for(int i = 0; i < m; ++i) cin >> b[i], sb[i] = b[i];
  if(n > m) dfs(0, 1);
  else if(n < m) dfs(1, 1);
  else {
    dfs(0, 0.5);
    for(int i = 0; i < n; ++i) sa[i] = a[i];
    for(int i = 0; i < m; ++i) sb[i] = b[i];
    dfs(1, 0.5);
  }
  cout << setprecision(12) << fixed << wa << ' ' << wb << ' ' << te << endl;
  return 0;
}