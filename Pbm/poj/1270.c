// 2025/9/27
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, a[25], dir[30][30];
int topo[25], vis[30], indegree[30];

int cmp(const void* a, const void* b) {
  return (*(const int*)a - *(const int*)b);
}

void dfs(int z, int cnt) {
  topo[cnt] = z;
  if(cnt == n-1) {
    for(int i = 0; i < n; ++i) printf("%c", topo[i]+'a');
    printf("\n");
    return;
  }
  vis[z] = 1;
  for(int i = 0; i < n; ++i) {
    if(!vis[a[i]] && dir[z][a[i]]) --indegree[a[i]];
  }
  for(int i = 0; i < n; ++i) {
    if(!indegree[a[i]] && !vis[a[i]]) dfs(a[i], cnt+1);
  }
  for(int i = 0; i < n; ++i) {
    if(!vis[a[i]] && dir[z][a[i]]) ++indegree[a[i]];
  }
  vis[z] = 0;
}

int main() {
  char s[205];
  int len;
  while(gets(s) != NULL) {
    memset(dir, 0, sizeof(dir));
    memset(vis, 0, sizeof(vis));
    memset(indegree, 0, sizeof(indegree));
    len = strlen(s); n = 0;
    for(int i = 0; i < len; ++i){
      if(s[i] >= 'a' && s[i] <= 'z') {
        a[n++] = s[i]-'a';
      }
    }
    qsort(a, n, sizeof(int), cmp);
    gets(s);
    len = strlen(s);
    int first = 1;
    for(int i = 0; i < len; ++i) {
      int st, ed;
      if(s[i] >= 'a' && s[i] <= 'z') {
        if(first) {
          first = 0;
          st = s[i]-'a';
        } else {
          first = 1;
          ed = s[i]-'a';
          dir[st][ed] = 1;
          ++indegree[ed];
        }
      }
    }
    for(int i = 0; i < n; ++i) {
      if(!indegree[a[i]]) {
        dfs(a[i], 0);
      }
    }
    printf("\n");
  }
  return 0;
}