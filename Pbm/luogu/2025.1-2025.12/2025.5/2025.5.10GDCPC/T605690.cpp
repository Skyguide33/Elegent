//2025/5/
#include <bits/stdc++.h>
using namespace std;

long long a[100005], b[100005], btail, bhead;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  long long bias, n, x, m; cin >> n >> x >> m;
  bias = x - x%m; x %= m;
  long long ans = 0;
  while(a[x] == 0 && x != 0 && n > 0) {
    ++a[x]; --n; b[btail++] = x;
    ans += x;
    x = (x*x) % m;
  }
  while(x != 0 && b[bhead] != x && bhead < btail) ++bhead;
  long long sum = 0;
  for(int i = bhead; i < btail; ++i) {
    sum += b[i];
  }
  if(n > 0 && x != 0) {
    ans += n/(btail-bhead) * sum;
    n %= (btail-bhead);
    for(int i = bhead; i < bhead+n; ++i) {
      ans += b[i];
    }
  }
  cout << ans+bias << endl;
  return 0;
}