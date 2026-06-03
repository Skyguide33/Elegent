//2025/1/19
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  long long F = 0, B = 0;
  cin >> n;
  vector<long long>a;
  for(int i = 0; i < n; i++) {
    long long t;
    cin >> t;
    if(!a.empty()) {
      bool input = 1;
      for(unsigned j = 0; j < a.size(); j++) {
        if(t <= a[j]) {
          a.insert(a.begin()+j, t);
          input = 0;
          break;
        }
      }
      if(input) a.push_back(t);
    }
    else a.push_back(t);
  }

  while(!a.empty()) {
    if(a.front() > F) {
      F += a.front();
      a.erase(a.begin());
    } else {
      unsigned i = 0;
      while(i < a.size() && a.at(i) <= F) i++;
      i--;
      F += a.at(i);
      a.erase(a.begin()+i);
    }
    if(a.empty()) break;
    if(a.front() > B) {
      B += a.front();
      a.erase(a.begin());
    } else {
      unsigned i = 0;
      while(i < a.size() && a.at(i) <= B) i++;
      i--;
      B += a.at(i);
      a.erase(a.begin()+i);
    }
  }
  cout << F << ' ' << B;
  return 0;
}