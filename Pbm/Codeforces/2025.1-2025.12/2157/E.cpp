//2025/11/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, k; cin >> n >> k;
  int tt;
  vector<int> freq(3*n+1);
  for(int i = 1; i <= n; ++i) cin >> tt,++freq[tt];
  // cout << "t1" << endl;
  bool flag = 0;
  for(int i = 1; i <= 2*n; ++i) {
    if(freq[i] > k) {
      flag = 1; 
      break;
    }
  }
  if(!flag) {
    cout << 0 << endl;
    return;
  }
  
  auto check = [&] (int num) -> bool {
    vector<int> fq = freq;
    stack<int> st;
    for(int i = 3*n; i >= 1; --i) {
      //cout << "t2" << endl;
      if(fq[i] == 0) st.push(i);
      while(fq[i] > 1 && st.top() <= i+num) {
        --fq[i];
        ++fq[st.top()];
        st.pop();
      }
      if(fq[i] > 1) {
        fq[i+num] += fq[i]-1;
        fq[i] = 1;
      }
    }
    for(int i = 3*n; i >= 1; --i) {
      if(fq[i] > k) return 0;
    }
    return 1;
  };

  int ans = 0;
  for(int i = 1<<20; i; i >>= 1) {
    if(!check(ans+i)) ans += i;
  }
  cout << ans+1 << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}