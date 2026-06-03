//2025/1/22
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n, Q;
  cin >> n >> Q;
  vector<int>res;
  for(int i = 0; i < n; i++) {
    string func;
    cin >> func;
    int a, b, c, result;
    a = stoi(func.substr(0, func.find("x")));
    func = func.substr(func.find("x"));
    b = stoi(func.substr(1, func.find("=")));
    func = func.substr(func.find("=")+1);
    c = stoi(func);
    //cout << func << endl;
    //cout << a << ' ' << b << ' ' << c << endl;
    result = (c-b) / a;
    bool same = 0;
    for(int& x: res) {
      if(x == result) {
        same = 1;
        break;
      }
    }
    if(!same) res.push_back(result);
  }
  for(int i = 0; i < Q; i++) {
    int min, max, count = 0;
    cin >> min >> max;
    for(int& x: res) {
      if(x >= min && x <= max) count++;
    }
    cout << count << endl;
  }
  return 0;
}