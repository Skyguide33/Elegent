//2026/3/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int s[200005], a[200005], tail;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, q; cin >> n >> q >> a[1];
  s[++tail] = 1; 
  int state = 0;
  for(int i = 2; i <= n; ++i) {
    cin >> a[i];
    if(a[i] > a[i-1]) {
      if(state != 1) {
        s[++tail] = i;
        state = 1;
      } else ++s[tail];
    } else {
      if(state != 2) {
        s[++tail] = i;
        state = 2;
      } else ++s[tail];
    }
  }
  // for(int i = 1; i <= tail; ++i) cout << s[i] << ' ';
  // cout << endl;
  while(q--) {
    int l, r; cin >> l >> r;
    int posl = upper_bound(s+1, s+tail+1, l)-s-1;
    int posr = lower_bound(s+1, s+tail+1, r)-s;
    if(posr-posl == 1) cout << (a[l] < a[r]? 'u': 'd') << endl;
    else if(posr-posl == 2) cout << (a[l] < a[l+1]? 't': 'v') << endl;
    else cout << '?' << endl;
  }
  return 0;
}