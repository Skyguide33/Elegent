//2025/8/27
#include <stdio.h>

int gcd(int a, int b) { 
  int t;
  while(b != 0) {
    t = a%b;
    a = b; b = t;
  }
  return a;
} 

int abs(const int& x) {return x<0? -x: x; } 

struct pos {
  int x, y;
  int det(const pos &a) { return x*a.y-a.x*y; }
} p[2];

int main() {
  int T; scanf("%d", &T);
  for(int tt = 1; tt <= T; ++tt) {
    int m; scanf("%d", &m);
    p[0] = {0, 0};
    int I = 0, E = 0, A = 0;
    for(int i = 1; i <= m; ++i) {
      scanf("%d %d", &p[i%2].x, &p[i%2].y);
      E += abs(gcd(p[i%2].x, p[i%2].y));
      p[i%2].x += p[(i+1)%2].x;
      p[i%2].y += p[(i+1)%2].y;
      A += p[i%2].det(p[(i+1)%2]);
    }
    A *= -1;
    I = (A-E+2)/2;
    printf("Scenario #%d:\n%d %d %.1f\n\n", tt, I, E, A/2.);
  }
}