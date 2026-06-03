//2025/8/28
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define endl '\n'

void solve() {
  int n, q; cin >> n >> q;
  vector<ll> a(n+1);
  tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> tr;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    tr.insert(a[i]);
  }
  int mid = n-n/2;
  while(q--) {
    int p, v; cin >> p >> v;
    tr.erase(tr.upper_bound(a[p]));
    a[p] += v;
    tr.insert(a[p]);
    cout << tr.order_of_key(*tr.find_by_order(mid)) << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}