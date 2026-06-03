//2025/1/20
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> point[n];
  long long sum[n] = {};
  for(int i = 0; i < m; i++) {
    int task;
    cin >> task;
    long long lsum = sum[0], lpoint = 0;
    for(int j = 1; j < n; j++) {
      if(sum[j] < lsum) {
        lsum = sum[j];
        lpoint = j;
      }
    }
    point[lpoint].push_back(i+1);
    sum[lpoint] += task;
  }
  for(int i = 0; i < n; i++) {
    for(auto& x: point[i]) cout << x << ' ';
    if(point[i].empty()) cout << 0;
    cout << endl;
  }
  return 0;
}