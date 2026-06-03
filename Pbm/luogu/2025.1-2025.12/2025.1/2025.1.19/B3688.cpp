//2025/1/19
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, t;
  cin >> n;
  vector<int>a;
  for(int i = 0; i < n; i++) {
    cin >> t;
    a.push_back(t);
  }
  do{
    a.insert(a.begin(), a.back());
    a.pop_back();
    for(int& x: a) cout << x << ' ';
    cout << endl;
  } while(a[n-1] != n);
  return 0;
}