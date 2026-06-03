//2025/8/27
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define endl '\n'

char s[1505];

ull BKDRHash(char *s) {
  ull P = 2, H = 0;
  while(*s) H = H*P + *(s++);
  return H;
}

void solve() {
  int n; cin >> n;
  set<ull> st;
  while(n--) {
    cin >> s;
    st.insert(BKDRHash(s));
  }
  cout << st.size() << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; //cin >> T;
  while(T--) solve();
  return 0;
}