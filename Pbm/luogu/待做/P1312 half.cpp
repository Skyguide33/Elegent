//2025/9/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct state {
  int a[6][8], rest;
} s[72];


void modify(int x, int y, int op, int idx) {
  s[idx] = s[idx-1];
  if(s[idx].a[x+op][y]) swap(s[idx].a[x][y], s[idx].a[x+op][y]);
  else {
    s[idx].a[x+op][y] = s[idx].a[x][y];
    int i = y;
    for(; s[idx].a[x][i+1] != 0; ++i) s[idx].a[x][i] = s[idx].a[x][i+1];
    s[idx].a[x][i+1] = 0;
  }
  
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;

  return 0;
}