//2025/10/13
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[10] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

bool cmp(int a, int b) { return a < b; }

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  nth_element(a, a+5, a+10, cmp);
  for(int i = 0; i < 10; ++i) cout << a[i] << ' ';
  cout << endl;
  return 0;
}