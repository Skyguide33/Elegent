//2024/12/20-2025/2/18
#include <bits/stdc++.h>
using namespace std;

int mil[100005], a[100005], num[100005];

int main() {
    int ans1 = 0, ans2 = 0, n = 0;
    while (scanf("%d", &mil[n]) != -1) {
        int s = 0, imin = 0, imax = ans1-1, i = (imax+imin) / 2;
        if(ans1) {
          while(1) {
            if(mil[n] > a[i] && (i == 0 || mil[n] <= a[i-1])) {
              a[i] = mil[n];
              s = 1;
              break;
            } else if(mil[n] > a[i]) {
              imax = i-1;
            } else imin = i+1;
            if(imax < imin) break;
            else i = (imax+imin) / 2;
          }
        }
        if (s == 0) a[ans1++] = mil[n];
        n++;
    }
    for (int i = 0; i < n; i++) {
        int s = 0, jmax = ans2, jmin = 0, j = (jmax+jmin) / 2;
        if(ans2) {
          while(1) {
            if(num[j] >= mil[i] && (j == 0 || num[j-1] < mil[i])) {
              num[j] = mil[i];
              s = 1;
              break;
            } else if(num[j] >= mil[i]) {
              jmax = j-1;
            } else jmin = j+1;
            if(jmax < jmin) break;
            else j = (jmax+jmin) / 2;
          }
        }
        if (s == 0) num[++ans2] = mil[i];
    }
    printf("%d\n%d", ans1, ans2);
    return 0;
}