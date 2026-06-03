//2025/1/18
#include <iostream>
using namespace std;

int main() {
  int a, b, c, i = 2;
  cin >> a >> b >> c;
  //for(; a % i != b % i || a % i != c % i || b % i != c % i; i++);
  while(1){
    if(a%i == b%i && a%i == c%i) break;
    else i++;
  }
  cout << i;
  return 0;
}