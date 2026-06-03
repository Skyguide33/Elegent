//2025/2/23
#include <iostream>
using namespace std;

int main() {
  int ans = 0;
  char input[257];
  cin >> input;
  for(int i = 0; input[i] != '\0'; i++) {
    if(input[i] == '(') ans++;
    else if(input[i] == ')') {
      if(ans == 0) {
        ans = -1;
        break;
      }
      ans--;
    }
  }
  if(!ans) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}