//2025/3/7
#include <iostream>
using namespace std;

int a[100005];

bool cmp(int a, int b) { return a < b; }
int main() {
  int N;
  scanf("%d", &N);
  for(int i = 0; i < N; i++) scanf("%d", &a[i]);
  // 插入排序
#if 0
  for(int i = 1; i < N; i++) {
    int key = a[i];
    int j = i-1;
    while(j >= 0 && a[j] > key) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = key;
  }
#endif
  // 希尔排序
#if 1
  for(int gap = N/2; gap > 0; gap /= 2) {
    for(int i = gap; i < N; i++) {
      int key = a[i];
      int j = i-1;
      while(j-gap+1 >= 0 && a[j-gap+1] > key) {
        a[j+1] = a[j-gap+1];
        j -= gap;
      }
      a[j+1] = key;
    }
  }
#endif
  for(int i = 0; i < N; i++) printf("%d ", a[i]);
  printf("\n");
  return 0;
}