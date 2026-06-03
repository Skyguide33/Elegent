//2025/4/5
#include <bits/stdc++.h>
using namespace std;

int ind[100005];

bool cmp(char a, char b) { return a < b; }

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    for(int i = 1; i <= m; i++) cin >> ind[i];
    string c; cin >> c;
    sort(ind+1, ind+m+1);
    priority_queue<int, vector<int>, greater<int>> q;
    for(auto& x: c) q.push(int(x));
    s[ind[1]-1] = char(q.top()); q.pop();
    for(int i = 2; i <= m; i++) {
      if(ind[i] != ind[i-1]) {
        s[ind[i]-1] = char(q.top()); q.pop();
      }
    }
    cout << s << endl;
  }
  return 0;
}