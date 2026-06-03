//2026/5/27
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

float Q_rsqrt(float x) {
    float x2 = x * 0.5f;
    float y = x;

    int32_t i = *(int32_t*)&y;  // 把 32 bits 当整数读
    i = 0x5f3759df - (i >> 1);  // 魔法
    y = *(float*)&i;

    // 牛顿迭代法
    y = y * (1.5f - x2 * y * y);          // 一次
    // y = y * (1.5f - x2 * y * y);      // 可选第二次
    return y;
}

float Q_sqrt(float x) {
    float y = x;

    int32_t i = *(int32_t*)&y;  // 把 32 bits 当整数读
    i = 0x1fbd1df5 + (i >> 1);  // 魔法
    y = *(float*)&i;

    // 牛顿迭代法
    y = y/2+x/(y*2);     // 一次
    // y/2+x/(y*2);      // 可选第二次
    return y;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  cout << hex << 0x5f3759df/3 << endl;
  for(int i = 1; i <= n; ++i) {
    float d; cin >> d;
    // cout << "num: " << d << ", sqrt: " << sqrt(d) << ", Q_sqrt: " << 1/Q_rsqrt(d) << endl;
    cout << "num: " << d << ", sqrt: " << sqrt(d) << ", Q_sqrt: " << Q_sqrt(d) << endl;
  }
  return 0;
}