//2025/10
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[10005], b[10005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 0; i < n; ++i) b[i] = -1;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i]; a[i] += a[i-1];
    int mod = a[i]%n;
    if(b[mod] > -1) {
      int len = i-b[mod];
      cout << len << endl;
      for(int j = b[mod]+1; j <= i; ++j) cout << a[j]-a[j-1] << endl;
      break;
    } else b[mod] = i;
  }
  return 0;
}