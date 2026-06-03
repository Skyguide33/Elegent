//2025/7/27
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int day[] = {2,3,5,7,11,13,17,19,23,29,31,37};
int y[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int m[1000], year[100000], totm, toty, t;

bool is_prime(int x) {
  for(int i = 2; i*i <= x; ++i) if(x%i == 0) return 0;
  return 1;
}
void init() {
  for(int i = 1; i <= 12; ++i) {
    for(int j = 1; day[j] <= year[i]; ++j) {
      t = i*100 + day[j];
      if(is_prime(t)) m[++totm] = t;
    }
  }
  for(int i = 0; i <= 9999; ++i) {
    for(int j = 1; j <= totm; ++j) {
      t = i*10000 + m[j];
      if(is_prime(t)) y[++toty] = t;
    }
  }
}

void solve() {
  string s; cin >> s;
  int ans = 0;
  bool same;
  for(int i = 1; i <= toty; ++i) {
    t = y[i]; same = 1;
    for(int i = 7; i >= 0; --i) {
      if(t%10 != s[i]-'0' && s[i] != '-') {
        same = 0;
        break;
      }
    }
    if(same) ++ans;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}