//2025/2/23
#include <iostream>
#include <stack>
using namespace std;

int main() {
  int ans = 0, num, ft = 1, num2;
  bool def = 0;
  string input;
  stack<int> s;
  cin >> input;
  for(unsigned i = 0; i < input.size()-1; i++) {
    if(isdigit(input[i])) {
      if(def) {
        num*= 10;
        num += input[i] - '0';
      } else {
        def = 1;
        num = input[i] - '0';
      }
    } else if(input[i] == '.' && def) {
      def = 0;
      s.push(num);
    } else if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
      num2 = s.top();
      s.pop();
      if(ft) {
        ans = s.top();  
        s.pop();
        ft = 0;
      }
      //cout << "num2 = " << num2 << endl;
      if(input[i] == '+') ans += num2;
      else if(input[i] == '-') ans -= num2;
      else if(input[i] == '*') ans *= num2;
      else ans /= num2;
      //cout << "ans = " << ans << endl;
    } 
  }
  cout << ans << endl;
  return 0;
}