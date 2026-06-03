#include <bits/stdc++.h>
using namespace std;

int p[20000000];

int main() {
  int n, m;
  cin >> n >> m;
  while(n--) {
    int pos;
    cin >> pos;
    p[pos + 1000000] ++;
  }
  for(int i = 1; i <= 2000000; i++) p[i] += p[i-1];
  //partial_sum(mine.begin(), mine.end(), mine.begin());
  int ans = 0;
  for(int step = 0; step <= m; step += 2) {
    int left = 1000000 - step / 2;
    int right = 1000000 + (m - step);
    ans = max(ans, p[right] - p[left - 1]);
    left = 1000000 - (m - step);
    right = 1000000 + step / 2;
    ans = max(ans, p[right] - p[left - 1]);
  }
  cout << ans << endl;
}