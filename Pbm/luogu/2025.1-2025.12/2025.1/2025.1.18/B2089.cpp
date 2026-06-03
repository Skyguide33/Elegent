//2025/1/18
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n];
  for(int& x: a) cin >> x;
  // for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n / 2; i++) {
    int t = a[i];
    a[i] = a[n-1-i];
    a[n-1-i] = t;
  }
  for(int& x: a) cout << x << ' ';
  return 0;
}