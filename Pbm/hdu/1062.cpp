//2025/2/23
#include <stdio.h>

int main() {
  int n, top = -1;
  char ch, stack[1005];
  scanf("%d", &n);
  while(n--) {
    while(1) {
      ch = getchar();
      if(ch == ' ' || ch == '\n' || ch == EOF) {
        while(top >= 0) {
          printf("%c", stack[top]);
          top--;
        }
        if(ch == '\n' || ch == EOF) break;
        printf(" ");
      } else {
        top++;
        stack[top] = ch;
      }
    }
    printf("\n");
  }
  return 0;
}