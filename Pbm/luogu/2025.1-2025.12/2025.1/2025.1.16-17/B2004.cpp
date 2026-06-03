//2025/1/17
#include <iostream>
#include <format>
using namespace std;

int main() {
  int a, b, c;
  // scanf("%d %d %d", &a, &b, &c);
  // printf("%8d %8d %8d", a, b, c);

  // cin >> a >> b >> c;
  // cout << right;
  // cout.width(8);
  // cout << a << ' ';
  // cout.width(8);
  // cout << b << ' ';
  // cout.width(8);
  // cout << c;
  
  cin >> a >> b >> c;
  cout << format("{0:>8} {1:>8} {2:>8}", a, b, c ) << endl;
  return 0;
}