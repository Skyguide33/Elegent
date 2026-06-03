//2025/9/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int sum3 = (3+999/3*3)*(999/3)/2;
  int sum5 = (5+999/5*5)*(999/5)/2;
  int sum15 = (15+999/15*15)*(999/15)/2;
  cout << sum3+sum5-sum15 << endl;
  return 0;
}
// 233168