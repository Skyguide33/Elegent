//2025/1/23
#include <iostream>
using namespace std;

inline bool good(int N) {
  while(N) {
    if(!(N%2)) return 0;
    N /= 10;
    if(N%2) return 0;
    N /= 10;
  }
  return 1;
}

int main() {
  int N, count = 0;
  cin >> N;
  for(register int i = 1; i <= N; i++) count += good(i);
  cout << count << endl;
  return 0;
}