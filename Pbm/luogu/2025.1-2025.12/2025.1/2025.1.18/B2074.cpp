//2025/1/18
#include <iostream>
using namespace std;

int main() {
  int a, b, res = 1;
  cin >> a >> b;
  while(b--) {
    res *= a;
    res %= 7;
  }
  switch(res) {
    case 1: 
      cout << "Monday" << endl;
      break;
    case 2: 
      cout << "Tuesday" << endl;
      break;
    case 3: 
      cout << "Wednesday" << endl;
      break;
    case 4: 
      cout << "Thursday" << endl;
      break;
    case 5: 
      cout << "Friday" << endl;
      break;
    case 6: 
      cout << "Saturday" << endl;
      break;
    case 0: 
      cout << "Sunday" << endl;
      break;
  } 
  return 0;
}