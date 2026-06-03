//2026/2/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[100005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, p; cin >> n >> p >> a[0];
  for(int i = 1; i < n; ++i) {
    cin >> a[i];
    a[i] = (a[i]+a[i-1])%p;
  }
  int l = 0, r = 0, sum = 0;
  map<int, int> mp;
  mp[0] = -1;
  for(int i = 0; i < n; ++i) {
    auto it = mp.upper_bound(a[i]);
    if(it == mp.end()) it = mp.begin();
    int new_sum = (a[i]-it->first+p)%p;
    if(new_sum > sum) {
      l = it->second+1;
      r = i;
      sum = new_sum;
    }
    mp[a[i]] = i;
  } 
  cout << l << ' ' << r << ' ' << sum << endl;
  return 0;
}