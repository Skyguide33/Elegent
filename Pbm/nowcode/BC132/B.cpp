//2026/5/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[6], maxn[6];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    char ch; int s; cin >> ch >> s;
    int tt = ch-'A';
    if(s > maxn[tt]) {
      maxn[tt] = s;
      a[tt] = i;
    }
  }
  bool flag = 0;
  int sum = 0;
  for(int i = 0; i < 6; ++i) {
    if(a[i] == 0 || maxn[i] < 60) {
      flag = 1;
      break;
    } else sum += maxn[i];
  }
  if(flag || sum < 420) cout << -1 << endl;
  else {
    for(int i = 0; i < 6; ++i) cout << a[i] << ' ';
    cout << endl;
  }
  return 0;
}