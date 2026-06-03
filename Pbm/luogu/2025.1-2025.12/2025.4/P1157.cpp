//2025/4/11
#include <bits/stdc++.h>
using namespace std;

int n, r, a[21];

void dfs(int now, int tail) {
  if(tail == r) {
    for(int i = 1; i <= r; i++) cout << setw(3) << a[i];
    cout << endl;
    return;
  }
  for(int i = now+1; n-i+1 >= r-tail; i++) {
    a[tail+1] = i;
    dfs(i, tail+1);
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> r;
  dfs(0, 0);
  return 0;
}