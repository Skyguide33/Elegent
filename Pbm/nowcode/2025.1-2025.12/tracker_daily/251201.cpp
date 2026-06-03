//2025/12/1
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k; cin >> n >> k;
  vector<vector<int>> a(n+1, vector<int> (n+1));
  for(int i = 1; i <= n; ++i) a[i][i] = k;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
}