//2025/1/20
#include <iostream>
using namespace std;

int main() {
  char input[100];
  cin.getline(input, 100);
  int len = 0;
  while(input[len]) len++;
  for(int i = 0; i+1 <= len/2; i++) {
    if(input[i] != input[len-1-i]) {
      cout << "no" << endl;
      return 0;
    }
  }
  cout << "yes" << endl;
  return 0;
}