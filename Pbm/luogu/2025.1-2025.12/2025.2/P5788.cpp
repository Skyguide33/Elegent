//2025/2/23
#include <stdio.h>

int num[3000005], ans[3000005], s[3000005];

int main() {
  int n, top = -1;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) scanf("%d", &num[i]);
  for(int i = n; i >= 1; i--) {
    while(top != -1 && num[s[top]] <= num[i]) top--;
    if(top == -1) ans[i] = 0;
    else ans[i] = s[top];
    top++;
    s[top] = i;
  }
  for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}