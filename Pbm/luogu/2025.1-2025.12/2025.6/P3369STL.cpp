//2025/6/4
#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  while(n--) {
    int opt, x; cin >> opt >> x;
    if(opt == 1) v.insert(lower_bound(v.begin(), v.end(), x), x);
    if(opt == 2) v.erase(lower_bound(v.begin(), v.end(), x));
    if(opt == 3) cout << lower_bound(v.begin(), v.end(), x) - v.begin() + 1 << endl;
    if(opt == 4) cout << v[x-1] << endl;
    if(opt == 5) cout << v[lower_bound(v.begin(), v.end(), x)-v.begin()-1] << endl;
    if(opt == 6) cout << v[upper_bound(v.begin(), v.end(), x)-v.begin()] << endl;
  }
  return 0;
}