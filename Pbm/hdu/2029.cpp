//2025/4/19
#include <iostream>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    string ipt; cin >> ipt;
    int len = ipt.length();
    bool flag = 1;
    for(int i = 0; i < len; ++i) {
      if(ipt[i] != ipt[len-i-1]) {
        cout << "no" << endl;
        flag = 0;
        break;
      }
    }
    if(flag) cout << "yes" << endl;
  }
  return 0;
}