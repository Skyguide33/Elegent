//2026/3/9
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define endl '\n'
#define P 131

ull p[10005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  p[0] = 1;
  for(int i = 1; i <= 10000; ++i) p[i] = p[i-1]*P;
  set<ull> st;
  for(int i = 1; i <= n; ++i) {
    string tt; cin >> tt;
    ull hash = 0;
    for(char ch: tt) hash = hash*P+ch;
    st.insert(hash);
  }
  cout << st.size() << endl;
  return 0;
}