//2025/2/22
#include <stdio.h>

int h[100005], ans[1000005], s[1000005];

int main() {
  int N, top = -1;
  scanf("%d", &N);
  for(int i = 1; i <= N; i++) scanf("%d", &h[i]);
  for(int i = N; i >= 1; i--) {
    while(top >= 0 && h[s[top]] <= h[i]) top--;
    if(top == -1) ans[i] = 0;
    else ans[i] = s[top];
    top++;
    s[top] = i;
  }
  for(int i = 1; i <= N; i++) printf("%d\n", ans[i]);
  return 0;
}