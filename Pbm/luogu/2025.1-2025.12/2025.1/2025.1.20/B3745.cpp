//2025/1/20
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m, r;
  cin >> n >> m >> r;
  vector<int>f1(n);
  vector<int>p1(n);
  vector<int>f2(n);
  vector<int>p2(n);
  for(int& x:f1) cin >> x;
  for(int& x:p1) cin >> x;
  for(int& x:f2) cin >> x;
  for(int& x:p2) cin >> x;
  while(n--) {
    int order;
    cin >> order;
    order--;
    int index = -1;
    for(unsigned i = 0; i < f2.size(); i++) {
      if(f1[order] == f2[i] && p1[order] < p2[i]) {
        if(index > -1 && p2[index] > p2[i] || index == -1) index = i;
      }
    }
    if(index > -1) {
      f2.erase(f2.begin()+index);
      p2.erase(p2.begin()+index);
    }
  }
  cout << p2.size();
  return 0;
}