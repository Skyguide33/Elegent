//2025/9/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[100005], b[100005], n, ans1, ans2;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  while(cin >> a[++n]) {
    if(ans1 && a[n] > b[100001-ans1]) {
      *(lower_bound(b+100001-ans1, b+100001, a[n])-1) = a[n];
    } else b[100001-(++ans1)] = a[n];
  }
  --n;
  b[++ans2] = a[1];
  for(int i = 2; i <= n; ++i) {
    int pos = lower_bound(b+1, b+ans2+1, a[i])-b;
    if(pos <= ans2) b[pos] = a[i];
    else b[++ans2] = a[i];
  }
  cout << ans1 << endl << ans2 << endl;
  return 0;
}