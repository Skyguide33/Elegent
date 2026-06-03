//2025/11/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  vector<int> sum, num;
  char ch;
  for(int i = 1; i <= 100; ++i) {
    num.clear();
    for(int j = 1; j <= 50; ++j) {
      cin >> ch; num.push_back(ch-'0');
    }
    reverse(num.begin(), num.end());
    int len = num.size();
    if(sum.size( ) < (size_t)len) sum.resize(len);
    int r = 0, j = 0;
    for(; j < len; ++j) {
      r += sum[j]+num[j];
      sum[j] = r%10;
      r /= 10;
    }
    while(r) {
      if((size_t)j >= sum.size()) sum.push_back(r);
      else {
        r += sum[j];
        sum[j] = r%10;
      }
      r /= 10; ++j;
    }
  }
  reverse(sum.begin(), sum.end());
  for(int i = 0; i < 10; ++i) cout << sum[i];
  cout << endl;
  return 0;
}

// 5537376230