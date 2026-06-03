//2026/1/16
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int get_n(int num, int k) {

}

void solve() {
  int n, k, tt; cin >> n >> k;
  vector<int> a4, a2, a1, pw;
  pw.push_back(1);
  while(pw.back() <= n) pw.push_back(pw.back()*(1+k));
  for(int i = 1; i <= n; ++i) {
    cin >> tt;
    if(tt%4 == 0) a4.push_back(i);
    else if(tt%2 == 0) a2.push_back(i);
    else a1.push_back(i);
  }
  stringstream out;
  auto get_ans = [&]()->string {
    while(1) {
      int cnt = 0;
      while(!a1.empty()) {
        if(a4.back()) return "-1";
        out << a1.back() << ' ' << a4.back() << endl;
        ++cnt;
        if(cnt == n) {
          a4.pop_back();
          cnt = 0;
        }
        else a1.pop_back();
      }
      if(cnt < k && !a2.empty()) {
        out << a4.back() << ' ' << a2.back() << endl;
      }
    }
  };
  
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}