//2025/1/23
#include <iostream>
using namespace std;

void score(string game, int n) {
  int c0 = 0, c1 = 0;
  for(int i = 0; game[i] != 'E'; i++) {
    if(game[i] == 'W') c0++;
    else c1++;
    if((c0 >= n && c0 - c1 >= 2) || (c1 >= n && c1 - c0 >= 2)) {
      cout << c0 << ':' << c1 << endl;
      c0 = c1 = 0;
    }
  }
  cout << c0 << ':' << c1 << endl;
}
int main() {
  string game, jd;
  while(cin >> jd) game += jd;
  score(game, 11);
  cout << endl;
  score(game, 21);
  return 0;
}