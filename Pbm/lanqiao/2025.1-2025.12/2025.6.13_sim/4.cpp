//2025/6/13
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

int n, m, a[N], diff[N];

bool check(int x) {
  int cnt = 0;
  bool flag = 0;
  for(int i = 1; i <= n; ++i) {
    if(diff[i] > x) cnt += (diff[i]+x-1)/x-1; 
    if(diff[i] > x) flag = 1;
    // 绝招可抵抗一次铺路次数
  }
  if(cnt-flag <= m) return 1;
  return 0;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    diff[i] = a[i] - a[i-1];
  }
  int l = 1, r = N;
  while(l < r) {
    int mid = (l+r) / 2;
    if(check(mid)) r = mid;
    else l = mid + 1;
  }
  cout << l << endl;
  return 0;
}