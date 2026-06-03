//2025/3/17 2025/5/1 rewrite
#include <bits/stdc++.h>
using namespace std;

struct stu {
  int l = 0, r = 0;
  bool v = 1;
};

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int N, now = 1; cin >> N;
  stu P[N+2];
  for(int i = 2; i <= N; i++) {
    int k, p; cin >> k >> p;
    if(p) {
      if(P[k].r) {
        P[i].r = P[k].r;
        P[P[k].r].l = i;
      }
      P[k].r = i;
      P[i].l = k;
    } else {
      if(P[k].l) {
        P[i].l = P[k].l;
        P[P[k].l].r = i;
      }
      P[k].l = i;
      P[i].r = k;
    }
  }
  int M;
  cin >> M;
  while(M--) {
    int k;
    cin >> k;
    P[k].v = 0;
  }
  while(P[now].l) now = P[now].l;
  cout << now << ' ';
  while(P[now].r) {
    now = P[now].r;
    if(P[now].v) cout << now << ' ';
  }
  return 0;
}