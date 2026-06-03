//2025/1/20
#include <iostream>
#include <cstring>
using namespace std;

int main() {
  char input[33];
  cin >> input;
  int len = 0;
  while(input[len]) len++;
  if(!strcmp(&input[len-3],"ing")) input[len-3] = '\0';
  else if(!strcmp(&input[len-2], "er") || !strcmp(&input[len-2], "ly")) input[len-2] = '\0';
  cout << input << endl;
  return 0;
}