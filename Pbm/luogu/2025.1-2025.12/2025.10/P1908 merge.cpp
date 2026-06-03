//2025/10/16
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[500005], b[500005];
ll ans;

void Merge(int *l, int *mid, int *r) {
  int *p1 = l, *p2 = mid, cnt = 0;
  while(p1 < mid && p2 < r) {
    if(*p1 > *p2) {
      ans += mid-p1;
      b[cnt++] = *(p2++);
    } else b[cnt++] = *(p1++);
  }
  while(p1 < mid) b[cnt++] = (*p1++);
  while(p2 < r) b[cnt++] = (*p2++);
  for(int i = 0; i < cnt; ++i) {
    *(l++) = b[i];
  }
}

void Merge_sort(int* l, int *r) {
  if(l+1 >= r) return;
  int *mid = l+(r-l)/2;
  Merge_sort(l, mid);
  Merge_sort(mid, r);
  Merge(l, mid, r);
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  Merge_sort(a+1, a+n+1);
  cout << ans << endl;
  return 0;
}