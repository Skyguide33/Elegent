//2025/11/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 1000000

int num[N+5];

void init() {
  for(int i = 1; i <= N; ++i) {
    vector<int> a(10, 0);
    int tt = i;
    while(tt) {
      if(tt%10) ++a[tt%10];
      tt /= 10;
    }
    for(int j = i*2; j <= N; j += i) {
      vector<int> b(10, 0);
      tt = j;
      while(tt) {
        if(tt%10) ++b[tt%10];
        tt /= 10;
      }
      bool flag = 1;
      for(int k = 1; k < 10; ++k) {
        if(a[k] != b[k]) {
          flag = 0;
          break;
        }
      }
      if(flag) num[j] = 1;
    }
  }
  for(int i = 1; i <= N; ++i) num[i] += num[i-1];
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  init();
  int t; cin >> t;
  while(t--) {
    int l, r; cin >> l >> r;
    cout << num[r]-num[l-1] << endl;
  }
  return 0;
}