//2025/1/16
#include<stdio.h>
using namespace std;
int n;
int main(){
	int n, a[30], r[30];
	scanf("%d", &n);
	r[1] = r[2] = 1;
	for(int i = 3; i <= 30; i++) r[i] = r[i-1] + r[i-2];
  for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		printf("%d\n", r[a[i]]);
	}
	return 0;
}