//2026/5/16
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int px[200005], py[200005], qx[200005], qy[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, s; cin >> n >> s;
  ll pxsum = 0, pysum = 0, qxsum = 0, qysum = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> px[i] >> py[i] >> qx[i] >> qy[i];
    pxsum += px[i];
    pysum += py[i];
    qxsum += qx[i];
    qysum += qy[i];
  }
  int tx = (qxsum-pxsum)/2+px[s];
  int ty = (qysum-pysum)/2+py[s];
  for(int i = 1; i <= n; ++i) {
    if(qx[i] == tx && qy[i] == ty) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}