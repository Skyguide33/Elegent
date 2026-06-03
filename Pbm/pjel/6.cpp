//2025/11/20
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int sq = 101*101*100*100/4, sum = 0;
  for(int i = 1; i <= 100; ++i) sum += i*i;
  cout << sq-sum << endl;
  return 0;
}

// 25164150