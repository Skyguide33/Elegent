//2025/9/25 pbds
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> tr;
  int n; cin >> n;
  while(n--) {
    int opt, x; cin >> opt >> x;
    if(opt == 1) tr.insert(x);
    else if(opt == 2) tr.erase(tr.upper_bound(x));
    else if(opt == 3) cout << tr.order_of_key(x)+1 << endl;
    else if(opt == 4) cout << *tr.find_by_order(x-1) << endl;
    else if(opt == 5) cout << *tr.find_by_order(tr.order_of_key(x)-1) << endl;
    else cout << *tr.lower_bound(x) << endl;
  }
  return 0;
}