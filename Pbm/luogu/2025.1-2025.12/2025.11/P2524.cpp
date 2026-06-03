//2025/9/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[10], b[10], f[10];

int main() {
  f[0] = 1;
  for(int i = 1; i < 10; ++i) f[i] = f[i-1]*i;
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  char ch;
  for(int i = 1; i <= n; ++i) {
    cin >> ch;
    a[i] = ch-'0';
  }
  int res = 1;
  for(int i = 1; i <= n; ++i) {
    int cnt = a[i]-1;
    for(int j = 1; j < a[i]; ++j) {
      if(b[j]) --cnt;
    }
    res += cnt*f[n-i];
    b[a[i]] = 1;
  }
  cout << res << endl;
  return 0;
}