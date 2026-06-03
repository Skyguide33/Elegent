//2025/5/5
#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x) & -(x))

int tree[100005], N; 

int sum(int x) {
  int ans = 0;
  while(x > 0) {
    ans += tree[x];
    x -= lowbit(x);
  }
  return ans;
}

void update(int x, int d) {
  while(x <= N) {
    tree[x] += d;
    x += lowbit(x);
  }
} 

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  while(1) {
    cin >> N;
    if(N == 0) break;
    memset(tree, 0, sizeof(tree));
    for(int i = 1; i <= N; ++i) {
      int a, b; cin >> a >> b;
      update(a, 1); update(b+1, -1);
    }
    for(int i = 1; i <= N; ++i) {
      cout << sum(i)<< ' ';
    }
    cout << endl;
  }
  return 0;
}