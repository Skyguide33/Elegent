//2025/4/28
#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  int sum = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    if(a[i] > a[i-1]) sum += a[i] - a[i-1];
  }
  cout << sum << endl;
  return 0;
}