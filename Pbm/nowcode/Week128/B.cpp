//2026/1/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Pos {
  int id, x, y; 
} p[4];

bool cmp(Pos a, Pos b) { 
  if(a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}
int main() {
  cin.tie(0) -> sync_with_stdio(0);
  for(int i = 1; i <= 3; ++i) {
    p[i].id = i;
    cin >> p[i].x >> p[i].y;
  }
  sort(p+1, p+4, cmp);
  cout << p[2].id << endl;
  return 0;
}