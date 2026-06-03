//2025/10/9
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll a[100005], b[100005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i]; 
  }
  for(int i = 1; i <= n; ++i) {
    cin >> b[i]; 
  }
  sort(a+1, a+n+1);
  sort(b+1, b+n+1);
  map<int, set<pair<int, int>>> mp;
  priority_queue<int, vector<int>, greater<int>> q;
  for(int i = 1; i <= n; ++i) {
    int num = a[i]+b[1];
    mp[num].insert({i, 1});
    q.push(num);
  }
  for(int i = 1; i <= n; ++i) {
    cout << q.top() << ' '; 
    auto [pa, pb] = *mp[q.top()].begin(); 
    mp[q.top()].erase({pa, pb}); q.pop();
    if(++pb <= n) {
      int num = a[pa]+b[pb];
      mp[num].insert({pa, pb});
      q.push(num);
    }
  }
  return 0;
}