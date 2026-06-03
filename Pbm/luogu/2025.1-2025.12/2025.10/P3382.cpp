//2025/10/13
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n;
double a[14];

double f(double mid) {
  double res = 0;
  for(int i = n; i >= 0; --i) res += a[i]*pow(mid, i);
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  double l, r; cin >> n >> l >> r;
  for(int i = n; i >= 0; --i) cin >> a[i];
  while(r-l > 1e-7) {
    double k = (r-l)/3, mid1 = l+k, mid2 = l+k*2;
    if(f(mid1) > f(mid2)) r = mid2;
    else l = mid1;
  }
  cout << l << endl;
  return 0;
}