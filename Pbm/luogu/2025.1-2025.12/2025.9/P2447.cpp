//2025/9/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool a[2005][1005];
int n, m;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> m >> n;
  char ch; 
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m+1; ++j) {
      cin >> ch; a[i][j] = ch-'0';
    }
  }
  int i = 1; bool flag = 0;
  for(int k = m; k <= n; ++k) {
    for(int j = 1; j < i; ++j) {
      if(a[k][j])
        for(int l = 1; l <= m+1; ++l) {
          if(a[k][l] == a[j][l]) a[k][l] = 0;
          else a[k][l] = 1;
        }
    }
    for(; i <= m; ++i) {
      bool flag = 0;
      for(int j = i; j <= k; ++j) {
        if(a[j][i]) {
          flag = 1;
          for(int l = 1; l <= m+1; ++l) swap(a[j][l], a[i][l]);
          for(int j = 1; j <= k; ++j) {
            if(j != i && a[j][i]) {
              for(int l = 1; l <= m+1; ++l) {
                if(a[j][l] == a[i][l]) a[j][l] = 0;
                else a[j][l] = 1;
              }
            }
          }
        }
      }
      if(!flag) break;
    }
    if(i == m+1) {
      cout << k << endl;
      for(int j = 1; j <= m; ++j) {
        if(a[j][m+1]) cout << "?y7M#" << endl;
        else cout << "Earth" << endl;
      }
      flag = 1;
      break;
    } 
  } 
  if(!flag) cout << "Cannot Determine" << endl;
  return 0;
}