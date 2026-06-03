//2025/4/11
#include <bits/stdc++.h>
using namespace std;

int a[10005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int N, M; cin >> N >> M;
  for(int i = 0; i < N; i++) cin >> a[i];
  while(M--) next_permutation(a, a+N);
  for(int i = 0; i < N; i++) cout << a[i] << ' ';
  cout << endl;
  return 0;
}