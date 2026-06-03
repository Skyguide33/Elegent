//2026/4/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int L[101];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> L[i];
  int ans = 0;
  for(int i = 1; i <= n-2; ++i) {
    for(int j = i+1; j <= n-1; ++j) {
      for(int k = j+1; k <= n; ++k) {
        if(L[i] != L[j] && L[i] != L[k]) {
          int a[3] = {L[i], L[j], L[k]};
          sort(a, a+3);
          if(a[0]+a[1] > a[2]) ++ans;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}