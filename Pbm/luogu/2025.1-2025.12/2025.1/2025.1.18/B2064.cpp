//2025/1/18
#include <iostream>
using namespace std;

int main() {
  int a[31], n, t;
  a[1] = a[2] = 1;
  for(int i = 3; i <= 30; i++) {
    a[i] = a[i-1] + a[i-2];
  }
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> t;
    cout << a[t] << endl;
  }
  return 0;
}