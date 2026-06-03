//2026/4/2
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, k, a; cin >> n >> k;
  ll sum = 0;
  priority_queue<int, vector<int>, greater<int>> q;
  for(int i = 1; i <= n; ++i) {
    cin >> a;
    q.push(a); 
    if((int)q.size() > (i-1)/k) {
      sum += q.top(); q.pop();
    } 
  }
  cout << sum << endl;
  return 0;
}