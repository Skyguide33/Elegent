//2025/1/22
#include <iostream>
using namespace std;

int main() {
#if 0
  char input[10001], pre = 0;
  int count = 1;
  cin >> input;
  for(int i = 0; input[i] != '\0'; i++) {
    if(pre == 0) pre = input[i];
    else if(input[i] == pre) count++;
    else {
      cout << count << pre;
      pre = input[i];
      count = 1;
    }
  }
  cout << count << pre;
#endif
#if 1
  string input, ans;
  int count = 1;
  cin >> input;
  char pre = input[0];
  for(unsigned i = 1; i <= input.length(); i++) {
    if(pre == input[i]) count++;
    else {
      ans += to_string(count) + pre;
      pre = input[i];
      count = 1;
    }
  }
  cout << ans << endl;
#endif
  return 0;
}
