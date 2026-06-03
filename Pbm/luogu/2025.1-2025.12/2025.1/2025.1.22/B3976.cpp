//2025/1/22
#include <iostream>
using namespace std;

int main() {
  string input, ans;
  cin >> input;
#if 0
  for(int i = 0; i < input.length(); i++) {
    if(input[i] >= 'A' && input[i] <= 'Z' || input[i] >= 'a' && input[i] <= 'z') {
      cout << input[i];
    }
  }
  cout << endl;
#endif
#if 0
  for(unsigned i = 0; i < input.length(); i++) {
    if((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z')) {
      ans.push_back(input[i]);
    }
  }
  cout << ans << endl;
#endif
#if 1
  for(auto& c: input) {
    if(isalpha(c)) {
      ans += c;
    }
  }
  cout << ans << endl;
#endif 
  return 0;
}
