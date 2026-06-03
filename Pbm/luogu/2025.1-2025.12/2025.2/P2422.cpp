//2025/2/17
#include <iostream>
#include <stack>
using namespace std;

long long N, a[100001], sum[100001], f[100001], ans;
stack<int>q;

int main() {
  scanf("%lld", &N);
  q.push(0);
  for(int i = 1; i <= N; i++) scanf("%lld", &a[i]);
  for(int i = 1; i <= N+1; i++) {
    sum[i] = sum[i-1] + a[i];
    while(a[q.top()] > a[i]) {
      f[q.top()] += sum[i-1] - sum[q.top()];
      q.pop();
    }
    f[i] = sum[i] - sum[q.top()];
    q.push(i);
  }
  for(int i = 1; i <= N; i++) {
    if(ans < a[i]*f[i]) ans = a[i]*f[i];
  }
  printf("%lld", ans); 
  return 0;
}