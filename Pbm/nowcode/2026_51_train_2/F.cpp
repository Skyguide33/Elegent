//2026/5/1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

pair<int, int> a[1000005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    a[i].second = i;
    cin >> a[i].first;
  }
  sort(a+1, a+n+1);
  int l = 1, r = n;
  for(int i = 1; i < n; ++i) {
    int mid = upper_bound(a+l, a+r+1, {(a[l].first+a[r].first)>>1, 0})-a;
    cout << "mid=" << mid << ' ' << (a[l].first+a[r].first)/2 << endl;
    if(r-mid+1 >= mid-l) {
      cout << a[l].second << ' ';
      ++l;
    }
    else {
      cout << a[r].second << ' ';
      --r;
    }
    cout << endl;
  }
  cout << a[l].second << endl;
  return 0;
}