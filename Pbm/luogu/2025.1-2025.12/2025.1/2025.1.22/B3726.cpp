//2025/1/22
#include <iostream>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  string s[n+1];
  for(int i = 1; i <= n; i++) cin >> s[i];
  for(int i = 0; i < q; i++) {
    int opt;
    cin >> opt;
    if(opt == 1) {
      int x, y, i;
      cin >> x >> y >> i;
      s[y] = s[y].insert(i, s[x]);
    } else {
      int y;
      cin >> y;
      cout << s[y] << endl;
    }
  }
  return 0;
}