#include <iostream>
#include <deque>
using namespace std;

int main() {
  int num = 0, ans = 0;
  // int ceil = 1;
  // for(int i = 1; i <= 24; i++) ceil <<= 1;
  // cout << ceil << endl;
  while(num < 16777216) {
    // cout << (1024&3072) << endl;
    // return 0;
    int c = 1, cnt = 0;
    bool add1 = 1;
    deque<bool>q;
    for(int i = 1; c < 16777216; i++) {
      if(q.size() == 5) q.pop_front();
      //cout << "num=" << num << ", c=" << c << ", ((c&num) != 0)=" << ((c&num) != 0) << endl;
      q.push_back(((c&num) != 0));
      int sum = 0;
      for(auto& x: q) sum += x;
      if(sum > 3) {
        add1 = 0;
        //cout << num << endl;
        break;
      }
      c <<= 1;
    }
    if(add1) ans++;
    num++;
  }
  cout << ans << endl;
  return 0;
}