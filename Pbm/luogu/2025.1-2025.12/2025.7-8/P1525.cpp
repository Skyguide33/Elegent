//2025/8/27 rewrite
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct R {
  int a, b, c;
} p[100005];

int s[20005], b[20005];

int find_set(int &x) {
  if(x != s[x]) s[x] = find_set(s[x]);
  return s[x];
}

void merge_set(int &x, int &y) {
  int rx = find_set(x), ry = find_set(y);
  s[rx] = ry;
}

bool cmp(R &x, R &y) { return x.c > y.c; }

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= m; ++i) cin >> p[i].a >> p[i].b >> p[i].c;
  sort(p+1, p+m+1, cmp);
  for(int i = 1; i <= n; ++i) s[i] = i;
  for(int i = 1; i <= m+1; ++i) {
    if(find_set(p[i].a) == find_set(p[i].b)) {
      cout << p[i].c << endl;
      break;
    }
    if(!b[p[i].a]) b[p[i].a] = p[i].b;
    else merge_set(b[p[i].a], p[i].b);
    if(!b[p[i].b]) b[p[i].b] = p[i].a;
    else merge_set(b[p[i].b], p[i].a);
  }
  return 0;
}