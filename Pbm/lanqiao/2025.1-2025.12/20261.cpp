//2025/6/14
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

int n, l, r;
ll jc[1000005];

vector<int> e[100005];

ll nums(int sons) {
  int L = l-1, R = r-1;

}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i <= n-1; ++i) {
    int u, v; cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  cin >> l >> r;


  return 0;
}