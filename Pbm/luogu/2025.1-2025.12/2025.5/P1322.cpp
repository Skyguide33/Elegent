//2025/5/9
#include <bits/stdc++.h>
using namespace std;

long long getans() {
  long long ans = 0;
  char ch;
  while(cin >> ch) {
    string t; long long num;
    if(ch == 'F') {
      cin >> t >> num;
      ans += num;
    } else if(ch == 'B') {
      cin >> t >> num;
      ans -= num;
    } else if(ch == 'R') {
      cin >> t >> num;
      char ch; cin >> ch;
      ans += num * getans();
    } else break;
  }
  return ans;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cout << abs(getans()) << endl;
  return 0;
}