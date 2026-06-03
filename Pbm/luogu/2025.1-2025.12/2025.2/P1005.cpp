//2025/2/28
#include <bits/stdc++.h>
using namespace std;

vector<int> mul(vector<int>a, int b) {
  int r = 0;
  for(int i = 0; i < a.size(); i++) {
    r += a.at(i)*b;
    a.at(i) = r % 10;
    r /= 10;
  }
  while(r) {
    a.push_back(r%10);
    r /= 10;
  }
  return a;
}

vector<int> add(vector<int>a, vector<int>b) {
  int r = 0;
  if(a.size() >= b.size()) {
    for(int i = 0; i < a.size(); i++) {
      r += a.at(i);
      if(i < b.size()) r+= b.at(i);
      a.at(i) = r%10;
      r /= 10;
    }
    if(r) a.push_back(1);
    return a;
  } else {
    for(int i = 0; i < b.size(); i++) {
      r += b.at(i);
      if(i < a.size()) r+= a.at(i);
      b.at(i) = r%10;
      r /= 10;
    }
    if(r) b.push_back(1);
    return b;
  }
}

vector<int> max1(vector<int>a, vector<int>b) {
  if(a.size() > b.size()) return a;
  else if(a.size() < b.size()) return b;
  else {
    for(int i = a.size()-1; i >= 0; i--) {
      if(a.at(i) > b.at(i)) return a;
      else if(a.at(i) < b.at(i)) return b;
    }
    return a;
  }
}
vector<int>p[81],dp[81][81];
int a[81];
vector<int> f(int l, int r, int k) {
  if(dp[l][r].size()) return dp[l][r];
  if(l == r) {
    dp[l][r] = mul(p[k], a[l]);
  }
  else {
    dp[l][r] = max1(add(f(l+1,r,k+1), mul(p[k], a[l])),add(f(l,r-1,k+1),mul(p[k], a[r])));
  }
  return dp[l][r];
}

int main() {
  int n, m;
  vector<int>ans(1,0);
  cin >> n >> m;
  p[0].push_back(1);
  for(int i = 1; i < 81; i++) p[i] = mul(p[i-1],2);
  while(n--) {
    for(int i = 0; i < m; i++) cin >> a[i];
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < m; j++) dp[i][j].clear();
    }
    ans = add(ans, f(0, m-1, 1));
  }
  for(int i = ans.size()-1; i >= 0; i--) cout << ans.at(i);
  cout << endl;
  return 0;
}