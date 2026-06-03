//2025/4/1
#include <bits/stdc++.h>
using namespace std;

pair<int, int> bin_search1(int *a, int n, int x) {
  int l = 0, r = n;
  while(l < r) {
    int mid = l + (r-l) / 2;
    if(a[mid] >= x) r = mid;
    else l = mid + 1;
  }
  return make_pair(a[l], l);
}

pair<int, int> bin_search2(int *a, int n, int x) {
  int l = -1, r = n-1;
  while(l < r) {
    int mid = l + (r-l+1) / 2;
    if(a[mid] <= x) l = mid;
    else r = mid - 1;
  }
  return make_pair(a[l], l);
}

int main() {
  int a[10] = {1,3,4,4,6,8,10,13,15,16};
  int c, d;
  tie(c, d) = bin_search1(a, 10, 5);
  cout << c << endl;
  tie(c, d) = bin_search2(a, 10, 5);
  cout << c << endl;
  cout << *(lower_bound(a, a+10, 5)) << endl;
  cout << *(upper_bound(a, a+10, 5)-1) << endl;
  return 0;
}