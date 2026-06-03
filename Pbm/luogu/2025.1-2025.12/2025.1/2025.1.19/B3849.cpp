//2025/1/19
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<char>ch{'0','1','2','3','4','5','6','7','8','9',
  'A','B','C','D','E','F','G','H','I','J','K','L','M','N',
  'O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  int N, R;
  cin >> N >> R;
  ch.resize(R);
  int t = R;
  while(N >= t) {
    t*=R;
  }
  t/= R;
  while(N) {
    cout << ch[N/t];
    N %= t;
    t /= R;
  }
  while(t) {
    cout << '0';
    t /= R;
  }
  return 0;
}