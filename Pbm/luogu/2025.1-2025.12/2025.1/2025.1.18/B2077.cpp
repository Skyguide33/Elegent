//2025/1/18
#include <iostream>
using namespace std;

int main() {
  long long N;
  scanf("%lld", &N);
  while(!(N%2)) {
      printf("%lld/2=", N);
      N/=2;
      printf("%lld\n", N);
  }
  while(N!=1) {
    printf("%lld*3+1=", N);
    N = N*3+1;
    printf("%lld\n", N);
    while(!(N%2)) {
      printf("%lld/2=", N);
      N/=2;
      printf("%lld\n", N);
   }
  }
  printf("End");
  return 0;
}