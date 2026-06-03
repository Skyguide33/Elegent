//2026/4/29
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[100005];
int prime[100005], vis[100005], cnt;

void eular_sieve() {
  for(int i = 2; i <= 100000; ++i) {
    if(!vis[i]) {
      prime[++cnt] = i;
      vis[i] = i;
    }
    for(int j = 1; j <= cnt; ++j) {
      if(i*prime[j] > 100000) break;
      vis[i*prime[j]] = prime[j];
      if(i%prime[j] == 0) break; 
    }
  }
}

void init() {
  eular_sieve();
  for(int i = 10000; i < 100000; ++i) {
    string s = to_string(i);
    sort(s.begin(), s.end());
    bool flag = 1;
    while(flag) {
      int num = stoi(s);
      if(num >= 10000 && !binary_search(prime+1, prime+cnt+1, num)) {
        a[i] = num;
        break;
      }
      flag = next_permutation(s.begin(), s.end());
    }
    if(a[i] == 0) a[i] = -1;
  } 
}

void solve() {
  int n; cin >> n;
  cout << a[n] << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  init();
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}