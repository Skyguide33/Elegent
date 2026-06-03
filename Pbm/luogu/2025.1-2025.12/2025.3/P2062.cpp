//2025/3/2
#if 0
#include <stdio.h>

int q[1000005], len;

void push(int x) {
  q[++len] = x;
  int i = len;
  while(i >= 2 && q[i] < q[i/2]) {
    int t = q[i];
    q[i] = q[i/2];
    q[i/2] = t;
    i /= 2;
  }
} 

void pop() {
  q[1] = q[len--];
  int i = 1;
  while(i*2 <= len) {
    int son = i*2;
    if(son < len && q[son] > q[son+1]) son++;
    if(q[i] > q[son]) {
      int t = q[i];
      q[i] = q[son];
      q[son] = t;
    } else break;
    i = son;
  }
}

inline int top() { return q[1]; }

int main() {
  int n, x, size = 0, ans = 0;
  scanf("%d", &n);
  while(n--) {
    scanf("%d", &x);
    push(x);
  }
  x = 0;
  do {
    if(size == x) {
      ans++;
      x = top();
      pop();
      size = 1;
    } else {
      x = top();
      pop();
      size++;
    }
  } while(len);
  if(size < x) ans--;
  printf("%d\n", ans);
  return 0;
}
#endif
#if 1
#include <stdio.h>

int as[1000005], bs[1000005];

int main() {
  int n, x, size = 0, ans = 0, tag = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &x);
    as[x]++;
  }
  x = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= as[i]; j++) {
      bs[++x] = i;
    }
  }
  for(int i = 1; i <= x; i++) {
    if(size == tag) {
      ans++;
      tag = bs[i];
      size = 1;
    } else {
      tag = bs[i];
      size++;
    }
  }
  if(size < tag) ans--;
  printf("%d\n", ans);
  return 0;
}

#endif