//2025/5/7
#include <bits/stdc++.h>
using namespace std;

int n, S, T, q[100005];
double a[100005], sum[100005];

bool check(double x) {
  for(int i = 1; i <= n; ++i) {
    sum[i] = sum[i-1] + a[i] - x;
  }
  int l = 1, r = 0; //维护一个单调递增的双端队列
  for(int i = S; i <= n; ++i) {
    if(l <= r && q[l] < i-T) ++l;
    while(l <= r && sum[i-S] < sum[q[r]]) --r;
    q[++r] = i-S;
    if(l <= r && sum[i] - sum[q[l]] >= 0) return 1;
  }
  return 0;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> S >> T;
  for(int i = 1; i <= n; ++i) cin >> a[i]; 
  double l = -1e4-1, r = 1e4+1;
  while(r-l >= 1e-6) {
    double mid = (l+r) / 2;
    if(check(mid)) l = mid;
    else r = mid;
  }
  cout.precision(3); cout << fixed << l << endl;
  return 0;
}