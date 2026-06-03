//2025/1/19
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, T, k, p = 0;
  cin >> n >> T;
  vector<int>a(n);
  vector<int>b;
  for(int &x: a) cin >> x;
  // for(int i = 1; i <= T; i++) {
  //   p = 0;
  //   cin >> k;
  //   for(int i = 1; i <= k; i++) {
  //     int t = 0;
  //     for(; p+t*(k-i+1)<n; t++) {
  //       a.insert(a.begin()+p+t, a.at(p+t*(k-i+1)));
  //       a.erase(a.begin()+p+t*(k-i+1)+1);
  //     }
  //     p += t;
  //   }
  // }
  while(T--) {
    cin >> k;
    for(int i = 1; i <= k; i++) {
      for(int j = 0; i+j*k-1 < n; j++) {
        b.push_back(a.at(i-1+j*k));
      }
    }
    a = b;
    b.clear();
  }
  for(int&x: a) cout << x << ' ';
  return 0;
}