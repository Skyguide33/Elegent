//2025/11/27
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'



void dfs(int n) {
  if(n == 0) cout << 0;
  else {
    bool flag = 0;
    for(int i = 15; i >= 0; --i) {
      if(n&(1<<i)) {
        if(flag) cout << '+';
        else flag = 1;
        if(i == 1) cout << 2;
        else {
          cout << "2("; dfs(i); cout << ')';
        }
      }
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  dfs(n);
  cout << endl;
  //for(int i = 0; i <= 20; ++i) dfs(i), cout << endl;
  return 0;
}