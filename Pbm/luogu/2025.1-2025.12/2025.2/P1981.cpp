//2025/2/23
#include <iostream>
#include <stack>
using namespace std;

int main() {
  int num;
  char c;
  int ans;
  stack<int>s;
  cin >> ans;
  ans %= 10000;
  s.push(ans);
  while(cin >> c >> num) {
    if(c == '+') {
      s.push(num);
    } else s.top() = (s.top()*num) % 10000;
  }
  ans = 0;
  while(s.size()) {
    ans += s.top();
    s.pop();
  }
  cout << ans % 10000 << endl;
  return 0;
}