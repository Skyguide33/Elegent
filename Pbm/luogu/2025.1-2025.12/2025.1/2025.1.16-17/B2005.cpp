//2025/1/17
#include <iostream>
#include <format>
using namespace std;

int main() {
  char a;
  // scanf("%c", &a);
  // printf("  %c\n", a);
  // printf(" %c%c%c\n", a, a, a);
  // printf("%c%c%c%c%c", a, a ,a ,a ,a);
  cin >> a;
  cout << format("{0:^5}", a) << endl;
  cout << format(" {0}{0}{0}", a) << endl;
  cout << format("{0}{0}{0}{0}{0}", a);
  return 0;
}