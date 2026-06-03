//2025/1/23
#include <iostream>
using namespace std;

short N;
char c[36] = {'0','1','2','3','4','5','6','7','8','9','A','B',
              'C','D','E','F','G','H','I','J','K','L','M','N',
              'O','P','Q','R','S','T','U','V','W','X','Y','Z'};

string s(short n) {
  string res;
  while(n) {
    res.insert(res.begin(), c[n%N]);
    n /= N;
  }
  return res;
}

int main() {
  cin >> N;
  for(short i = 1; i < N; i++) {
    for(short j = 1; j <= i; j++) {
      cout << s(i) << '*' << s(j) << '=' << s(i*j) << ' ';
    }
    cout << endl;
  }
  return 0;
}