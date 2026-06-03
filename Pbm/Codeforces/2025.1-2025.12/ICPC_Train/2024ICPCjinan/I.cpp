//2025/7/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int a[101];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int k = 0;
  vector<pair<int,int>> ans;
  priority_queue<int> q;
  int mini = 1, minn = 1;
  for(int i = mini; i <= n; ++i) {
    for(int j = mini; j <= n; ++j) {
      if(a[j] == j) ++mini;
      
    }
  }
  cout << k << endl;
  for(auto& [x, y]: ans) {
    cout << x << ' ' << y << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}