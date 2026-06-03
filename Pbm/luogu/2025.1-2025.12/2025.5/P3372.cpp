//2025/5/5 rewrite 2025/4/1
#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x) & -(x))

int n, m;

long long tree1[100005], tree2[100005];

void update(long long *Tree, int x, long long d) {
  while(x <= n) {
    Tree[x] += d;
    x += lowbit(x);
  }
}

long long sum(int x) {
  long long ans = 0;
  int k = x;
  while(x > 0) {
    ans += k*tree1[x] - tree2[x];
    x -= lowbit(x);
  }
  return ans;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  long long pre = 0, now;
  for(int i = 1; i <= n; ++i) {
    cin >> now; 
    update(tree1, i, now-pre);
    update(tree2, i, (i-1)*(now-pre));
    pre = now;
  }
  while(m--) {
    int p, x, y; cin >> p >> x >> y;
    if(p == 1) {
      long long k; cin >> k;
      update(tree1, x, k); update(tree1, y+1, -k);
      update(tree2, x, (x-1)*k); update(tree2, y+1, -y*k);
    } else {
      cout << sum(y) - sum(x-1) << endl;
    }
  }
  return 0;
}