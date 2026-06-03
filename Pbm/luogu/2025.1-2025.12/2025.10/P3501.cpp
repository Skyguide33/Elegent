//2025/10/21
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define endl '\n'
#define N 500005
#define P 131

char s[N];
ull f[N], b[N], p[N];
int n; ll ans;

void bin_search(int x) {
  int l = 0, r = min(x, n-x);
  while(l < r) {
    int mid = (l+r+1)>>1;
    if(f[x]-f[x-mid]*p[mid] == b[x+1]-b[x+mid+1]*p[mid]) l = mid;
    else r = mid-1;
  }
  ans += l;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  f[0] = p[0] = b[n] = 1;
  for(int i = 1; i <= n; ++i) {
    cin >> s[i];
    f[i] = f[i-1]*P + s[i];
    p[i] = p[i-1]*P;
  }
  for(int i = n; i >= 1; --i) b[i] = b[i+1]*P + '1'-s[i]+'0';
  for(int i = 1; i <= n-1; ++i) bin_search(i);
  cout << ans << endl;
  return 0;
}