//2025/3/17
#include <iostream>
#include <algorithm>
using namespace std;

inline bool cmp(const string& a, const string& b) {
  string ab = a + b, ba = b + a;
  for(int i = 0; i < ab.length(); i++) {
    if(ab.at(i) > ba.at(i)) return 1;
    if(ab.at(i) < ba.at(i)) return 0;
  }
  return 1;
}

int main() {
  int n;
  string ans;
  cin >> n;
  string num[n];
  for(int i = 0; i < n; i++) cin >> num[i];
  sort(num, num + n, cmp);
  for(int i = 0; i < n; i++) cout << num[i];
  cout << endl;
  return 0;
}