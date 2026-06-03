//2025/1/20
#include <iostream>
using namespace std;

int main() {
  char input[10001];
  cin.getline(input, 10000);
  int len = 0;
  while(input[len]) len++;
  for(int i = 0; i < len; i++) {
    if(input[i] >= 'b' && input[i] <= 'z' || input[i] >= 'B' && input[i] <= 'Z') input[i]--;
    else if(input[i] == 'a' || input[i] == 'A') input[i] += 25;
  }
  cout << input << endl;
  return 0;
}