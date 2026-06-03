//2025/11/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<int> getv(int n, int k) {
  if(k == n-1) return {n-1};
  else if(k == 1) {
    if(n == 5) return {2, 3};
    else if(n > 5) return {2, 3, n-4};
  } else {
    for(int i = 2; i < n; ++i) {
      int d_sum = n+i-2;
      if(d_sum%k) continue;
      int sum = d_sum/k;
      if(sum < i) continue;
      vector<int> res(i);
      // cout << "i=" << i << endl;
      for(int j = 0; j < i-1; ++j) res[j] = k;
      res[i-1] = (sum-i+1)*k;
      return res;
    }
  }
  return {};
}

void print(vector<int> &y) {
  int len = y.size();
  // cout << "y: ";
  // for(int i = 0; i < len; ++i) cout << y[i] << ' ';
  // cout << endl;
  if(len > 1) {
    for(int i = 1; i < len; ++i) {
      --y[i-1]; --y[i];
      cout << i << ' ' << i+1 << endl;
    }
  }
  int cnt = len;
  for(int i = 0; i < len; ++i) {
    while(y[i]) {
      --y[i]; ++cnt;
      cout << i+1 << ' ' << cnt << endl;
    }
  }
}

void solve() {
  int n, k; cin >> n >> k;
  auto y = getv(n, k);
  if(y.empty()) cout << "No" << endl;
  else {
    cout << "Yes" << endl;
    print(y);
  }
}


int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}