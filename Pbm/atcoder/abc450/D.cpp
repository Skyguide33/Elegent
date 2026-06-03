//2026/3/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, k; cin >> n >> k;
  set<int> st;
  for(int i = 1; i <= n; ++i) {
    int tt; cin >> tt;
    st.insert(tt%k);
  }
  if(st.size() == 1) cout << 0 << endl;
  else {
    vector<int> num;
    for(int x: st) num.push_back(x);
    int len = num.size();
    int maxd = 0;
    for(int i = 1; i < len; ++i) {
      maxd = max(maxd, num[i]-num[i-1]);
    }
    // cout << maxd << ' ' << k << endl;
    cout << min(k-maxd, num[len-1]-num[0]) << endl;
  }
  return 0;
}