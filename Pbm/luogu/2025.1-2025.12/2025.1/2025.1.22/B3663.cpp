//2025/1/22
#include <iostream>
using namespace std;

int main() {
  int ans = 0, pos;
  string input;
  cin >> input;
  while(input.length() && input.find("luogu") != string::npos) {
    ans++;
    input = input.substr(input.find("luogu")+5);
  }
  cout << ans << endl;
  return 0;
}