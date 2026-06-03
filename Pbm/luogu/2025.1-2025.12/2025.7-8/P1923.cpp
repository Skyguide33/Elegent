//2025/7/15
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int a[5000005];

void quick_sort(int *a, int *end) {
  int l = 0, r = end-a-1, key = a[(l+r+1)/2];
  while(l <= r) {
    while(a[l] < key) l++; 
    while(a[r] > key) r--; 
    if(l <= r) {
      int t = a[l];
      a[l] = a[r];
      a[r] = t;
      l++; r--; 
    }
  }
  // cout << "r+1=" << r+1 << ", l=" << l << endl;
  if(l > 0) quick_sort(a, a+r+1);
  if(r < end-1-a) quick_sort(a+l, end);
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, k; cin >> n >> k;
  for(int i = 0; i < n; ++i) cin >> a[i];
  quick_sort(a, a+n);
  cout << a[k] << endl;
  return 0;
}