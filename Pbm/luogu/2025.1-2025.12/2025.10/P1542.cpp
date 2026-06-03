//2025/9/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

int x[200005], y[200005], s[200005], n;

bool check(ld mid) {
  ld now = 0;
  for(int i = 1; i <= n; ++i) {
    now = max(now+s[i]/mid, (ld)x[i]);
    if(now > y[i]) return 0;
  }
  return 1;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> x[i] >> y[i] >> s[i];
  }
  ld l = 0, r = 1e7, mid;
  while(r-l >= 1e-4) {
    mid = (l+r)/2;
    if(check(mid)) r = mid;
    else l = mid;
  }
  cout.precision(2);
  cout << fixed << mid << endl;
  return 0;
}