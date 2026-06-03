//2026/3/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

char a[20000005];

int main() {
  freopen("D:/dev/code/ALGORITHM/Pbm/luogu/input", "r", stdin);
  // reopen("D:/dev/code/ALGORITHM/Pbm/luogu/output", "w", stdout);
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i+n] = a[i];
  }
  int i = 1, j = 2, k = 0;
  while(i <= n && j <= n) {
    k = 0;
    while(k < n && a[i+k] == a[j+k]) ++k;
    if(a[i+k] > a[j+k]) i += k+1;
    else j += k+1;
    if(i == j) ++j;
  }
  int srt = min(i, j), stop = srt+n;
  for(int i = srt; i < stop; ++i) cout << a[i];
  cout << endl;
  return 0;
}