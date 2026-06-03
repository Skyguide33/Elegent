//2025/4/
#include <bits/stdc++.h>
using namespace std;

int N, M; 
struct resent{ int a, b, c; } p[1000005];
int a[20005], b[20005];

int find_set(int p) {
  if(p != a[p]) a[p] = find_set(a[p]);
  return a[p];
} 

void merge_set(int x, int y) {
  int px = find_set(x), py = find_set(y);
  a[px] = py;
}

bool cmp(resent x, resent y) { return x.c > y.c; }

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> N >> M;
  for(int i = 1; i <= M; ++i) {
    cin >> p[i].a >> p[i].b >> p[i].c;
  }
  sort(p+1, p+M+1, cmp);
  for(int i = 1; i <= N; ++i) a[i] = i;
  for(int i = 1; i <= M+1; ++i) {
    if(find_set(p[i].a) == find_set(p[i].b)) {
      cout << p[i].c << endl;
      break;
    }
    if(!b[p[i].a]) b[p[i].a] = p[i].b;
    else {
      merge_set(b[p[i].a] , p[i].b);
    }
    if(!b[p[i].b]) b[p[i].b] = p[i].a;
    else {
      merge_set(b[p[i].b] , p[i].a);
    }
  }
  return 0;
}