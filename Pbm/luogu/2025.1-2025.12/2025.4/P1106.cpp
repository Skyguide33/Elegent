//2025/4/28
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string num; int k; cin >> num >> k;
  while(k) {
    int find_zero = -1;
    for(int i = 0; i < num.length(); ++i) {
      if(num[i] == '0') {
        find_zero = i;
        break;
      }
    }
    if(find_zero >= 0 && find_zero <= k) {
      k -= find_zero;
      while(find_zero--) num.erase(num.begin());
      while(num.length() && num[0] == '0') num.erase(num.begin()); 
    } else {
      int idx = num.length()-1;
      if(num.length() >= 2) {
        for(int i = 0; i < num.length()-1; ++i) {
          if(num[i] > num[i+1]) {
            idx = i; break;
          }
        }
      }
      num.erase(num.begin()+idx);
      --k;
    }
    if(num.empty()) {
      num = "0";
      break;
    }
  }
  cout << num << endl;
  return 0;
}