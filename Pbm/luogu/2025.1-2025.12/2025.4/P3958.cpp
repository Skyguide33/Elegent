//2025/4/29
#include <bits/stdc++.h>
using namespace std;

struct pos{ long long x, y, z; } p[1005];

long long dist(pos a, pos b) {
  return 1ll * (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
}
long long sett[1005];

bool cel[1005], flor[1005];

long long find_set(long long parent) {
  if(sett[parent] != parent) sett[parent] = find_set(sett[parent]);
  return sett[parent]; 
}

void merge_set(long long a, long long b) {
  long long pa = find_set(a);
  long long pb = find_set(b);
  sett[pa] = pb;
}

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  long long T; cin >> T;
  while(T--) {
    memset(cel, 0, sizeof(cel));
    memset(flor, 0, sizeof(flor));
    long long n, h, r; cin >> n >> h >> r;
    for(long long i = 1; i <= n; ++i) cin >> p[i].x >> p[i].y >> p[i].z;
    // make_set
    for(long long i = 1; i <= n; ++i) sett[i] = i;
    // merge_set
    for(long long i = 1; i <= n; ++i) {
      if(p[i].z + r >= h) cel[i] = 1;
      if(p[i].z - r <= 0) flor[i] = 1;
      for(long long j = i+1; j <= n; ++j) {
        if(dist(p[i],p[j]) <= 4ll*r*r) merge_set(i, j);
      }
    }
    bool flag = 1;
    for(long long i = 1; i <= n; ++i) {
      for(long long j = 1; j <= n; ++j) {
        if(cel[i] && flor[j] && find_set(i) == find_set(j)) {
          cout << "Yes" << endl;
          flag = 0;
          break;
        }
      }
      if(flag == 0) break;
    }
    if(flag) cout << "No" << endl;
  }
  return 0;
}