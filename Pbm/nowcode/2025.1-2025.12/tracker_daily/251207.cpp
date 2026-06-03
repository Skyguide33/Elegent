//2025/12/7
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[101];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, x; cin >> n >> x;
  int minx = 0, maxx = 0;
  a[0] = -50;
  cin >> a[1];
  int preid = 1, ass = a[1];
  if(a[1] == -999) preid = 0, ass = 50;
  for(int i = 2; i <= n; ++i) {
    cin >> a[i];
    if(a[i] == -999) {
      if(ass-x >= -50) {
        ++maxx;
        ass -= x;
      } else ass = 50;
    } else {
      if(ass-a[i] >= x) ++maxx;
      if((a[preid]-a[i]+i-preid-1)/(i-preid) >= x) ++minx;
      ass = a[i];
      preid = i;
    }
  }
  cout << maxx << ' ' << minx << endl;
  return 0;
}