//2025/1/20
#include <iostream>
using namespace std;

int main() {
  char input[101], ans[101];
  cin.getline(input, 100);
  int len = 0;
  while(input[len]) len++;
  for(int i = 0; i < len-1; i++) {
    ans[i] = input[i] + input[i+1];
  }
  ans[len-1] = input[0] + input[len-1];
  ans[len] = '\0';
  cout << ans << endl;
  return 0;
}