//2025/2/24
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  priority_queue<int, vector<int>, greater<int>>q;
  string s;
  while(getline(cin, s) && s != "END") {
    sort(s.begin(), s.end());
    int num = 1;
    for(unsigned i = 1; i <= s.length(); i++) {
      if(s[i] != s[i-1]) {
        q.push(num); num = 1;
      } else num++;
    }
    int ans = 0;
    if(q.size() == 1) ans = s.length();
    while(q.size() > 1) {
      int a = q.top(); q.pop();
      int b = q.top(); q.pop();
      q.push(a+b);
      ans += a+b;
    }
    q.pop();
    cout.precision(1);
    cout << fixed << s.length()*8 << ' ' << ans << ' ' << s.length()*8/double(ans) << endl;
  }
  return 0;
}