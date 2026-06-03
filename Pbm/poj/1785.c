// 2025/9/30
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#define N 50005
#define INF INT_MAX>>1
typedef struct {
  char s[21]; int ls, rs, fa, pri;
} Node;
Node t[N];

int cmp(const void *a, const void *b) {
  return strcmp(((const Node *)a)->s, ((const Node *)b)->s);
}

void build_tree(int n) {
  for(int i = 1; i <= n; ++i) {
    int pos = i-1;
    while(t[pos].pri < t[i].pri) pos = t[pos].fa;
    t[i].ls = t[pos].rs;
    t[t[i].ls].fa = i;
    t[pos].rs = i;
    t[i].fa = pos;
  }
}

void inorder(int x) {
  if(x == 0) return;
  printf("(");
  inorder(t[x].ls); 
  printf("%s/%d", t[x].s, t[x].pri);
  inorder(t[x].rs);
  printf(")");
}

int main() {
  int n; 
  while(scanf("%d", &n), n) {
    for(int i = 1; i <= n; ++i) {
      t[i].ls = t[i].rs = t[i].fa = 0;
      scanf(" %[^/]/%d", t[i].s, &t[i].pri);
      // printf("%s/%d ", t[i].s, t[i].pri);
    }
    // putchar('\n');
    t[0].ls = t[0].rs = t[0].fa = 0;
    t[0].pri = INF;
    qsort(t+1, n, sizeof(Node), cmp);
    // for(int i = 1; i <= n; ++i) {
    //   printf("%s/%d ", t[i].s, t[i].pri);
    // }
    build_tree(n);
    inorder(t[0].rs);
    putchar('\n');
    n = 0;
  }
  return 0;
}