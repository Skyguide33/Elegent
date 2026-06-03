#include <stdio.h>
#include <random>
#include <ctime>
#define MOD 400000000
#define N 200000

long long cnt = 0;
int a[N+5];
int count[MOD+5];
int tmp[N+5], len;

// 选择排序 4999950000  
void selection_sort(int *a, int *end) {
  for(int i = 0; i < end-a; i++) {
    int m = i;
    for(int j = i+1; j < end-a; j++) {
      cnt++;
      if(a[j] < a[m]) m = j;
    }
    int t = a[m];
    a[m] = a[i];
    a[i] = t;
  }
}
// 冒泡排序 4999950000 4999801215(Optimized) 
void bubble_sort(int *a, int *end) {
  for(int i = 0; i < end-a-1; i++) {
    bool swapped = 0;
    for(int j = 0; j < end-a-i-1; j++) {
      cnt++;
      if(a[j] > a[j+1]) {
        int t = a[j];
        a[j] = a[j+1];
        a[j+1] = t;
        swapped = 1;
      }
    }
    if(!swapped) break;
  }
  return;
}
// 插入排序 2494326880 
void insertion_sort(int *a, int *end) {
  for(int i = 1; i < end-a; i++) {
    int key = a[i];
    int j = i-1;
    while(j >= 0 && a[j] > key) {
      cnt++;
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = key;
  }
}
// 希尔排序 2861693 
void shell_sort(int *a, int *end) {
  for(int gap = (end-a)/2; gap > 0; gap /= 2) {
    for(int i = gap; i < end-a; i++) {
      int j = i-1;
      while(j-gap+1 > 0 && a[j-gap+1] > a[i]) {
        cnt++;
        a[j+1] = a[j-gap+1];
        j -= gap;
      }
      a[j+1] = a[i];
    }
  }
}
// 计数排序 200000 
void counting_sort(int *a, int *end) {
  int i, max = 0;
  for(int i = 0; i < end-a; i++) {
    cnt++;
    if(a[i] > max) max = a[i];
    count[a[i]]++;
  }
  i = 0;
  for(int j = 0; j <= max; j++) {
    while(count[j] > 0) {
      cnt++;
      a[i++] = j;
      count[j]--;
    }
  }
}
// 基数排序 2800081 
void radix_sort(int *a, int *end) {
  int max = 0, exp = 1;
  for(int i = 0; i < end-a; i++) {
    cnt++;
    if(a[i] > max) max = a[i];
  }
  while(max/exp) {
    int bucket[10] = {0};
    for(int i = 0; i < end-a; i++) {
      cnt++;
      bucket[(a[i]/exp)%10]++;
    }
    for(int i = 1; i < 10; i++) {
      cnt++;
      bucket[i] += bucket[i-1];
    }
    for(int i = end-a-1; i >= 0; i--) {
      cnt++;
      tmp[--bucket[(a[i]/exp)%10]] = a[i];
    }
    for(int i = 0; i < end-a; i++) {
      cnt++;
      a[i] = tmp[i];
    }
    exp *= 10;
  }
}
// 归并排序 3337856 
void Merge(int *a, int *mid, int *end) {
  int i = 0, j = mid-a, t = 0;
  while(a+i < mid && a+j < end) {
    cnt++;
    if(a[i] < a[j]) tmp[t++] = a[i++];
    else tmp[t++] = a[j++];
  }
    while(a+i < mid) {
      cnt++;
      tmp[t++] = a[i++];
    }
    while(a+j < end) {
      cnt++;
      tmp[t++] = a[j++];
    }
    for(int i = 0; i < t; i++) {
      cnt++;
      a[i] = tmp[i];
    }
}
void merge_sort(int *L, int *R) {
  if(L < R-1) {
    int *mid = L + (R-L)/2;
    merge_sort(L, mid);
    merge_sort(mid, R);
    Merge(L, mid, R);
  }
}
// 快速排序 1356988 
void quick_sort(int *a, int *end) {
  int l = 0, r = end-a-1, key = a[(l+r)/2];
  while(l <= r) {
    while(a[l] < key) { cnt++; l++; }
    while(a[r] > key) { cnt++; r--; }
    if(l <= r) {
      int t = a[l];
      a[l] = a[r];
      a[r] = t;
      l++; r--; 
    }
  }
  if(l > 0) quick_sort(a, a+r+1);
  if(r < end-1-a) quick_sort(a+l, end);
}
// 堆排序 1743575 
void push(int x) {
  tmp[++len] = x;
  int i = len;
  while(i >= 2 && tmp[i] < tmp[i/2]) {
    cnt++;
    int t = tmp[i];
    tmp[i] = tmp[i/2];
    tmp[i/2] = t;
    i /= 2;
  }
}
int top() { return tmp[1]; }

void pop() {
  tmp[1] = tmp[len--];
  int i = 1;
  while(i*2 <= len) {
    cnt++;
    int son = i*2;
    if(son < len && tmp[son+1] < tmp[son]) son++;
    if(tmp[son] < tmp[i]) {
      int t = tmp[i];
      tmp[i] = tmp[son];
      tmp[son] = t;
      i = son;
    } else break;
  }
}
void heap_sort(int *a, int *end) {
  for(int i = 0; i < end-a; i++) {
    cnt++;
    push(a[i]);
  }
  for(int i = 0; i < end-a; i++) {
    cnt++;
    a[i] = top();
    pop();
  }
}

int main() {
  srand((unsigned)time(0));
  for(int i = 0; i < N; i++) a[i] = (rand() * rand() + rand()) % MOD;
  // selection_sort(a, a+N);
  // bubble_sort(a, a+N);
  // insertion_sort(a, a+N);
  // shell_sort(a, a+N);
  // counting_sort(a, a+N);
  // radix_sort(a, a+N);
  // merge_sort(a, a+N);
  // quick_sort(a, a+N);
  // heap_sort(a, a+N);
  printf("cnt=%lld\n", cnt);
  for(int i = 0; i < N; i++) printf("%d ", a[i]);
  printf("\n");
}