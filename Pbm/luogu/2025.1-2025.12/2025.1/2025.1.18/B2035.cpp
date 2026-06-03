//2025/1/18
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  if(N > 0) cout << "positive";
  else if(N < 0) cout << "negative";
  else cout << "zero";
  return 0;
}