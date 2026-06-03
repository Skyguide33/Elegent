//2025/11/20
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  for(int a = 0; a <= 332; ++a) {
    for(int b = a+1; b < 1000-a-b; ++b) {
      int c = 1000-a-b;
      if(a*a+b*b == c*c) {
        // cout << a << ' ' << b << ' ' << c << endl;
        cout << a*b*c << endl;
        return 0;
      } else if(a*a+b*b > c*c) break;
    }
  }
}

// 31875000