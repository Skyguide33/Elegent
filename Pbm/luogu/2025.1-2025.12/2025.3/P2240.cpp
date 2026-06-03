//2025/3/9
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct{
  int m, v;
  double vpm;
}coin;

bool cmp(coin a, coin b) { return a.vpm > b.vpm; }

int main() {
  int N, T;
  double ans = 0;
  scanf("%d %d", &N, &T);
  coin C[N];
  for(int i = 0; i < N; i++) {
    scanf("%d %d", &C[i].m, &C[i].v);
    C[i].vpm = double(C[i].v)/C[i].m;
  }
  sort(C, C+N, cmp);
  for(int i = 0; i < N; i++) {
    if(T >= C[i].m) {
      T -= C[i].m;
      ans += C[i].v;
    } else {
      ans += C[i].vpm * T;
      break;
    }
  }
  printf("%.2lf\n", ans);
  return 0;
}