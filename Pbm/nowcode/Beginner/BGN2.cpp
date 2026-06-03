//2026/2/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int v[3], a[3];
  for(int i = 0; i < 3; ++i) cin >> v[i];
  for(int i = 0; i < 3; ++i) cin >> a[i];
  sort(v, v+3);
  sort(a, a+3);
  if(a[2] > v[1] && a[1] > v[0]) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}