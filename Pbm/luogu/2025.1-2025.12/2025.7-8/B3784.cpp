//2025/8/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct State {
  int id, sum;
};

bool cmp(State& a, State& b) {
  return a.sum > b.sum;
}

void solve() {
  int n, m, a, b, h, fav = 0; cin >> n >> m >> a >> b;
  vector<State> st(n+1); 
  for(int i = 1; i <= n; ++i) st[i].id = i;
  for(int i = 1; i <= a; ++i) {
    if(i == b) {
      int ht = 0;
      for(int j = 1; j <= n; ++j) {
        cin >> h;
        st[j].sum += h;
        if(h > ht) {
          ht = h;
          fav = j;
        }
      }
    }
    for(int j = 1; j <= n; ++j) {
      cin >> h;
      st[j].sum += h;
    }
  }
  sort(st.begin()+1, st.end(), cmp);
  bool flag = 0;
  for(int i = 1; i <= m; ++i) {
    if(st[i].id == fav) {
      flag = 1;
      break;
    }
  }
  if(flag) {
    cout << fav << ' ';
    for(int i = 1; i <= m; ++i) {
      if(st[i].id == fav) continue;
      cout << st[i].id << ' ';
    }
    cout << endl;
  } else {
    for(int i = 1; i < m; ++i) cout << st[i].id << ' ';
    cout << fav << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; //cin >> T;
  while(T--) solve();
  return 0;
}