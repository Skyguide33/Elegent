//2025/2/23
#include <stdio.h>
using namespace std;

int value[1005][1005];

int main() {
  int N, M, C, t, MaxValue = -1e9, MVX = 0, MVY = 0;
  scanf("%d %d %d", &N, &M, &C);
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      value[i][j] = value[i][j-1];
      scanf("%d", &t);
      value[i][j] += t;
    }
    for(int j = 1; j <= M; j++) {
      value[i][j] += value[i-1][j];
    }
  }
  for(int i = 1; i <= N-C+1; i++) {
    for(int j = 1; j <= M-C+1; j++) {
      t = value[i+C-1][j+C-1]-value[i+C-1][j-1]+value[i-1][j-1]-value[i-1][j+C-1];
      if(t > MaxValue) {
        MaxValue = t;
        MVX = i;
        MVY = j;
      }
    }
  }
  printf("%d %d", MVX, MVY);
  return 0;
}