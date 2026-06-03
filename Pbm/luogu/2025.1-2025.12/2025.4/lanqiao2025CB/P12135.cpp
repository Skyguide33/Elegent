//2025/4/15
#include <bits/stdc++.h>
using namespace std;

string a[2];
int dis[2][1000005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> a[0] >> a[1];
  int len = a[0].length();
  memset(dis, 0x3f3f3f3f, sizeof(dis));
  int f0 = a[0].find('#'), f1 = a[1].find('#');
  reverse(a[0].begin(), a[0].end());
  reverse(a[1].begin(), a[1].end());
  int l0 = len-a[0].find('#')-1, l1 = len-a[1].find('#')-1;
  if(f0 == -1) f0 = len; if(f1 == -1) f1 = len;
  reverse(a[0].begin(), a[0].end());
  reverse(a[1].begin(), a[1].end());
  if(f0 <= f1) dis[0][f0] = 0;
  else dis[1][f1] = 0;
  if(l0 == len) l0 = -1; if(l1 == len) l1 = -1;
  // cout << f0 << ' ' << f1 << ' ' << l0 << ' ' << l1 << endl;
  for(int i = min(f0, f1); i <= max(l0, l1); i++) {
    dis[0][i] = min(dis[0][i], dis[0][i-1]);
    if(a[0][i] == '.') dis[0][i]++; 
    dis[1][i] = min(dis[1][i], dis[1][i-1]);
    if(a[1][i] == '.') dis[1][i]++; 
    if(a[0][i] == '.') dis[0][i] = min(dis[0][i], dis[1][i]+1);
    else dis[0][i] = min(dis[0][i], dis[1][i]);
    if(a[1][i] == '.') dis[1][i] = min(dis[1][i], dis[0][i]+1);
    else dis[1][i] = min(dis[1][i], dis[0][i]);
  }
  // for(int i = 0; i < 2; i++) {
  //   for(int j = 0; j < len; j++) cout << dis[i][j] << ' ';
  //   cout << endl;
  // }
  cout << min(dis[0][max(l0,l1)], dis[1][max(l0,l1)]) << endl;
  return 0;
}