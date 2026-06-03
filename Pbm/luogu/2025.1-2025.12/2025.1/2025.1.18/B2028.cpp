//2025/1/18
#include <iostream>
#include <format>
using namespace std;

int main() {
  char a, b, c;

  // cin >> a >> b >> c;
  // cout << c << b << a;
  // scanf("%c%c%c", &a, &b, &c);
  // printf("%c%c%c", c, b ,a);
  cin >> a >> b >> c;
  cout << format("{}{}{}", c, b, a);
  return 0;
}