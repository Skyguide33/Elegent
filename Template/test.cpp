//2026/3/30
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n = 20;
  vector<int> s(n+1);
  iota(s.begin()+1, s.end(), 1);
  auto res = s | views::filter([](int x) { return x&1; })
              | views::drop(5)
              | views::take(3);
  for(int x: s) cout << x << ' ';
  cout << endl;
  for(int &x: res) {
    cout << x << ' ';
    x *= 10;
  }
  cout << endl;
  for(int x: s) cout << x << ' ';
  cout << endl;
  return 0;
}