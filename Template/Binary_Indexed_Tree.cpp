//2025/5/5
#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x) & -(x))

int a[1000005], tree[100005], n;

// 修改更新树状数组
void update(int x, int d) {
  while(x <= n) {
    tree[x] += d;
    x += lowbit(x); 
  }
}

// 查询a[1] ~ a[x]的前缀和
int sum(int x) {
  int ans = 0;
  while(x > 0) {
    ans += tree[x];
    x -= lowbit(x);
  }
  return ans;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n; //输入数组长度
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    update(i, a[i]);
  } 
  // 计算区间和
  cout << "a[5]-a[8]=" << sum(8) - sum(4) << endl;
  return 0;
}