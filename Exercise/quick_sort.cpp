//2025/8/21
#include <bits/stdc++.h>
using namespace std;
const int N = 100, MOD = 100;

int a[N+5];

void quick_sort(int *a, int *end) {
  int *i = a-1, *j = a;
  if(--end <= a) return;
  while(j < end) {
    if(*j <= *end) swap(*(++i), *j);
    ++j; 
  }
  swap(*(++i), *end);
  quick_sort(a, i);
  quick_sort(i, end+1);
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  srand((unsigned)time(0));
  for(int i = 0; i < N; ++i) a[i] = (rand() * rand() + rand()) % MOD;
  quick_sort(a, a+N);
  for(int i = 0; i < N; ++i) cout << a[i] << ' ';
  cout << endl;
  return 0;
}