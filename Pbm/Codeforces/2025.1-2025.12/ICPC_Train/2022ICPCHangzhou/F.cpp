//2025/11/9
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  set<string> st;
  for(int i = 1; i <= n; ++i) {
    int m; cin >> m;
    bool flag = 1;
    while(m--) {
      string s; cin >> s;
      if(s.find("bie") != -1 && !st.count(s)) {
        cout << s << endl;
        st.insert(s);
        flag = 0;
      } 
    }
    if(flag) cout << "Time to play Genshin Impact, Teacher Rice!" << endl;
  }
  return 0;
}