#include <bits/stdc++.h>
using namespace std;

struct Class{
  int l, q;
} C[10005];

bool cmp(Class x, Class y) { return (x.l-x.q) > (y.l-y.q); }

int main() {
  int n;
  long long sum = 0;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> C[i].l >> C[i].q;
    sum += C[i].q;
  }
  sort(C+1, C+n+1, cmp);
  for(int i = 1; i <= n/2; i++) {
    sum += C[i].l - C[i].q;
  }
  cout << sum << endl;
  return 0;
}