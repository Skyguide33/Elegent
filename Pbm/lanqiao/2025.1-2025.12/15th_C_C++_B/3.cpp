#include <cstdio>

int main() {
  int N, i = 0;
  scanf("%d", &N);
  for(; N >= 1; N--) {
    int m = N;
    while(1) {
      if(m % 2) m /= 10;
      else break;
      if(m % 2 == 0) m /= 10;
      else break;
      if(m == 0) {
        i++;
        break;
      }
    }
  }
  printf("%d\n", i);
}