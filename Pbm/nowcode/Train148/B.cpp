//2026/1/23
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int bit_num(int n) {
  int cnt = 0;
  while(n) {
    if(n&1) ++cnt;
    n >>= 1;
  } 
  return cnt;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, k; cin >> n >> k;
  vector<int> a(n+1);
  int avg_sum = 0, sum = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    avg_sum += i*a[i];
    sum += a[i];
  }
  bool flag = 0;
  for(int i = 1; i <= (1<<n)-1; ++i) {
    if(bit_num(i) == k) {
      int new_avg_sum = avg_sum, new_sum = sum;
      for(int j = 1; j <= n; ++j) {
        if((1<<(j-1))&i) {
          new_avg_sum -= j*a[j];
          new_sum -= a[j];
        }
      }
      if(1ll*avg_sum*new_sum == 1ll*new_avg_sum*sum) {
        flag = 1;
        break;
      }
    }
  }
  cout << (flag? "Yes": "No") << endl;
  return 0;
}