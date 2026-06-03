//2026/1/16
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

char s[7][10] = {"Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Violet"};

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int maxn = -1, maxi = 0, tt;
  for(int i = 0; i < 7; ++i) {
    cin >> tt;
    if(tt > maxn) {
      maxi = i;
      maxn = tt;
    }
  }
  cout << s[maxi] << endl;
  return 0;
}