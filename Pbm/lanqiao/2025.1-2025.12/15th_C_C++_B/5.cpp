//2025/4/8
#include <bits/stdc++.h>
using namespace std;

int H[100005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int N; cin >> N;
  int max_H = 0;
  for(int i = 1; i <= N; ++i) {
    int t; cin >> t;
    if(t > max_H) max_H = t;
    ++H[t];
  }
  for(int i = max_H; i >= 1; --i) {
    int ans[3] = {0}, top = 0, num = 0;
    for(int j = i; j <= max_H; j += i) {
      num += H[j];
      for(int k = 0; k < H[j] && top < 3; ++k) {
        ans[top++] = j;
      }
      if(num >= 3) break;
    }
    if(top >= 3) {
      for(int i = 0; i < 3; ++i)  cout << ans[i] << ' ';
      cout << endl;
      break;
    }
  }
  return 0;
}