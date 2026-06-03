//2025/1/18
#include <iostream>
using namespace std;

int main() {
  int a, b;
  char c;
  cin >> a >> b >> c;
  // if(c == '+') cout << a + b;
  // else if(c == '-') cout << a - b;
  // else if(c == '*') cout << a * b;
  // else if(c == '/' && b != 0) cout << a / b;
  // else if(c == '/' && b == 0) cout << "Divided by zero!";
  // else cout << "Invalid operator!";
  switch(c) {
    case '+':
      cout << a + b;
      break;
    case '-':
      cout << a - b;
      break;
    case '*':
      cout << a * b;
      break;
    case '/':
      if(b == 0) cout << "Divided by zero!";
      else cout << a / b;
      break;
    default:
    cout << "Invalid operator!";
  }
  return 0;
}