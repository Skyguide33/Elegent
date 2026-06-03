#if 1
#include <iostream>
#include <deque>
using namespace std;

int a[1000005];
int main() {
  int n, k;
  deque<int>min, max;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    while(!min.empty() && a[i] <= a[min.back()]) min.pop_back();
    min.push_back(i);
    if(i >= k-1) {
      printf("%d ", a[min.front()]);
      if(min.front() <= i-k+1) min.pop_front();
    }
  }
  printf("\n");
  for(int i = 0; i < n; i++) {
    while(!max.empty() && a[i] >= a[max.back()]) max.pop_back();
    max.push_back(i);
    if(i >= k-1) {
      printf("%d ", a[max.front()]);
      if(max.front() <= i-k+1) max.pop_front();
    }
  }
  printf("\n");
  return 0;
}
#endif

#if 0

#include <stdio.h>

int a[1000005], min[1000005], max[1000005];
int tmin = 0, tmax = 0, fmin = 0, fmax = 0;
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    while(tmin >= fmin && a[min[tmin]] >= a[i]) tmin--;
    min[++tmin] = i;
    if(i >= k-1) {
      printf("%d ", a[min[fmin]]);
      if(min[fmin] <= i-k+1) fmin++;
    }
  }
  printf("\n");
  for(int i = 0; i < n; i++) {
    while(tmax >= fmax && a[max[tmax]] <= a[i]) tmax--;
    max[++tmax] = i;
    if(i >= k-1) {
      printf("%d ", a[max[fmax]]);
      if(max[fmax] <= i-k+1) fmax++;
    }
  }
  return 0;
}
#endif
