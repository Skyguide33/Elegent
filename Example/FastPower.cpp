//2025/2/21
#include <iostream>
#include <vector>
using namespace std;

void test() {
  int base, power, r;
  vector<char>ans, temp;
  cout << "请分别输入底数和次数，中间用空格隔开：";
  cin >> base >> power;
  r = base;
  while(r) {
    ans.push_back(r%10);
    r /= 10;
  }
  for(int i = 1; i < power; i++) {
    r = 0;
    for(int j = 0; j < ans.size(); j++) {
      r += ans.at(j) * base;
      ans.at(j) = r % 10;
      r /= 10;
    }
    while(r) {
      ans.push_back(r % 10);
      r /= 10;
    }
  }
  for(int i = ans.size()-1; i >= 0; i--) {
    cout << int(ans.at(i));
  }
  cout << endl;
}

int main() {
  while(1) {
    test();
  }
  return 0;
}