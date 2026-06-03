//2025/11/23
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define endl '\n'

int len;

bool check(int l, int r) {
  int psum, asum;
  cout << 1 << ' ' << l << ' ' << r << endl;
  cin >> psum;
  cout << 2 << ' ' << l << ' ' << r << endl;
  cin >> asum;
  return asum-psum;
}

void solve() {
  int n; cin >> n;
  int l = 1, r = n; 
  while(l < r) {
    int mid = (l+r)>>1;
    if(check(1, mid)) r = mid;
    else l = mid+1;
  }
  int psum, asum;
  cout << 1 << ' ' << 1 << ' ' << n << endl;
  cin >> psum;
  cout << 2 << ' ' << 1 << ' ' << n << endl;
  cin >> asum;
  cout << "! " << l << ' ' << l+asum-psum-1 << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}