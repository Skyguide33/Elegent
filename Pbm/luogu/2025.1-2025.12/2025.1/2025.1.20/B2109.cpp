//2025/1/20
#include <iostream>
using namespace std;

int main() {
  char input[256];
  cin.getline(input,255);
  int num = 0;
  for(int i = 0; input[i] != '\0'; i++) {
    if(input[i] >= '0' && input[i] <= '9') num++;
  }
  cout << num << endl;
  return 0;

}