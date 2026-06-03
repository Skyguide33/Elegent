//2025/1/18
#include <iostream>
using namespace std;

int main() {
  long long m;
  short k, count = 0;
  cin >> m >> k;
  while(m) {
    if(m%10 == 3) count++;
    m/=10; 
  }
  if(k == count) cout << "YES";
  else cout << "NO";
  return 0;
}