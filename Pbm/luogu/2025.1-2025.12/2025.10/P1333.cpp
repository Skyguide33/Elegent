//2025/10/17
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int dge[500005], n, s[500005];

int find_set(int x) {
  return (x == s[x]? x: find_set(s[x]));
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  map<string, int> mp;
  string c1, c2;
  while(cin >> c1 >> c2) {
    if(!mp.count(c1)) {
      mp[c1] = ++n;
      s[n] = n;
    }
    if(!mp.count(c2)) {
      mp[c2] = ++n;
      s[n] = n;
    }
    int x = find_set(mp[c1]), y = find_set(mp[c2]);
    if(x != y) s[x] = y;
    ++dge[mp[c1]];
    ++dge[mp[c2]];
  }
  set<int> st;
  for(int i = 1; i <= n; ++i) {
    st.insert(find_set(s[i]));
  }
  if(st.size() > 1) {
    cout << "Impossible" << endl;
    return 0;
  }
  int cnt = 0;
  for(int i = 1; i <= n; ++i) {
    if(dge[i]%2) ++cnt;
  }
  if(cnt == 0 || cnt == 2) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  return 0;
}