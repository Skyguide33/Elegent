//2025/4/11
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int q; cin >> q;
  while(q--) {
    int a2, a3, a4, b4, b6; 
    cin >> a2 >> a3 >> a4 >> b4 >> b6;
    int ans = 0;
    // 2 3 4 sum
    tuple<int, int, int, int> q[] = {
      {0, 2, 0, 6},
      {1, 0, 1, 6},
      {3, 0, 0, 6},
      {1, 1, 0, 5},
      {0, 0, 1, 4},
      {2, 0, 0, 4},
      {0, 1, 0, 3},
      {1, 0, 0, 2}
    };
    vector<int> boards(b6, 6);
    boards.insert(boards.end(), b4, 4);
    for(auto &b: boards) {
      for(auto &[c2, c3, c4, sum]: q) {
        if(a2 >= c2 && a3 >= c3 && a4 >= c4 && b >= sum) {
          ans += sum;
          a2 -= c2; a3 -= c3; a4 -= c4;
          break;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}