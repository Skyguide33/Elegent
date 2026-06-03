//2025/7/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> t;

void solve() {
  t.clear();
  t.push_back(0);
  int n, k; cin >> n >> k;
  for(int i = 1; i <= n; ++i) t.push_back(i);
  while(t.size() > 2) {
    cout << t[1] << endl;
    for(int i = 1; i < t.size(); i += k-1) t.erase(t.begin()+i);
  }
  //cout << "k=" << k << ", ans=" << t[1] << endl;
  cout << t[1] << endl;
  printf("a");
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}