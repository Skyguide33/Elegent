//2025/3/21
#include <bits/stdc++.h>
using namespace std;

int n, vf[14], vd[28], vp[28], a[14], times;
//dfs(l,pre) l当前行数, pre上一行的位置
void dfs(int line) {
  if(line == n+1) {
    if(++times <= 3) {
      for(int i = 1; i <= n; i++) cout << a[i] << ' ';
      cout << endl;
    }
    return;
  }
  for(int i = 1; i <= n; i++) {
    if(vf[i] || vp[line+i-1] || vd[line-i+n]) continue;
    vf[i] = 1;
    vp[line+i-1] = 1;
    vd[line-i+n] = 1;
    a[line] = i;
    dfs(line+1);
    vf[i] = 0;
    vp[line+i-1] = 0;
    vd[line-i+n] = 0;
  }
  return;
}

int main() {
  cin >> n;
  dfs(1);
  cout << times << endl;
  return 0;
}