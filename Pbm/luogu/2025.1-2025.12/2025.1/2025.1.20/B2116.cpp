//2025/1/20
#include <iostream>
using namespace std;

int main() {
  char input[51];
  cin.getline(input, 50);
  int len = 0;
  while(input[len]) len++;
  for(int i = 0; i < len; i++) {
    input[i] ^= '\x20';
    if(input[i] >= 'a' && input[i] <= 'w' || input[i] >= 'A' && input[i] <= 'W') input[i] += 3;
    else input[i] -= 23;
  }
  for(int i = 0; i+1 <= len / 2; i++) {
    char t = input[len-1-i];
    input[len-1-i] = input[i];
    input[i] = t;
  }
  cout << input;
  return 0;
}