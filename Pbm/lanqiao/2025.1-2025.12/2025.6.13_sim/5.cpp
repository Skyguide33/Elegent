//2025/6/13
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  string s, add; cin >> s >> add;
  sort(add.begin(),add.end());
  for(int i = 0; i < s.length(); ++i) {
    if(add.empty()) break;
    if(s[i] > add.front()) {
      s.insert(s.begin()+i, add.front());
      add.erase(0, 1);
    }
  }
  if(!add.empty()) s.append(add);
  cout << s << endl;
  return 0;
}