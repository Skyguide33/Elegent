//2025/9/30
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e7+5;

struct Node {
  int ls, rs, fa, key, pri;
} t[N];

ll ans1, ans2;

void inorder(int x) {
  if(x == 0) return;
  // cout << "node " << t[x].key << endl;
  inorder(t[x].ls);
  ans1 ^= 1ll*t[x].key*(t[x].ls+1);
  ans2 ^= 1ll*t[x].key*(t[x].rs+1);
  inorder(t[x].rs);
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    t[i].key = i; cin >> t[i].pri;
  }
  for(int i = 1; i <= n; ++i) {
    int pos = i-1;
    while(t[pos].pri > t[i].pri) pos = t[pos].fa;
    t[i].ls = t[pos].rs;
    t[t[i].ls].fa = i;
    t[pos].rs = i;
    t[i].fa = pos;
  }
  inorder(t[0].rs);
  cout << ans1 << ' ' << ans2 << endl;
  return 0;
}