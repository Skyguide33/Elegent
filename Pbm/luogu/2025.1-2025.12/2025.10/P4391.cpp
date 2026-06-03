//2025/10/19
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define endl '\n'
#define P 131

char s[1000005];
ull h[1000005], p[1000005];

ull get_hash(int l, int r) {
  return h[r]-h[l-1]*p[r-l+1];
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  h[0] = 1;
  p[0] = 1;
  for(int i = 1; i <= n; ++i) {
    cin >> s[i];
    h[i] = h[i-1]*P+s[i];
    p[i] = p[i-1]*P;
  }
  for(int i = 1; i <= n; ++i) {
    ull h = get_hash(1, i);
    bool ok = 1;
    for(int j = i+1; j+i-1 <= n; j += i) {
      if(get_hash(j, j+i-1) != h) {
        ok = 0;
        break;
      }
    }
    if(ok && (n%i == 0 || get_hash(1, n%i) == get_hash(n/i*i+1, n))) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}