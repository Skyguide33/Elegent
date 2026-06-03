//2025/3/21
#include <bits/stdc++.h>
using namespace std;

int N, M, a[11], v[12];

void dfsC(int n, int m) {
  if(m == 0) {
    for(int i = 0; i < M; i++) 
      cout << a[i] << ' ';
    cout << endl;
    return;
  }
  for(int i = N-n+1; i <= N-m+1; i++) {
    a[M-m] = i;
    dfsC(N-i, m-1);
  }
  return;
}

void dfsA(int n, int m) {
  if(m == 0) {
    for(int i = 0; i < M; i++) 
      cout << a[i] << ' ';
    cout << endl;
    return;
  }
  for(int i = 1; i <= n; i++) {
    if(!v[i]) {
      v[i] = 1;
      a[M-m] = i;
      dfsA(n, m-1);
      v[i] = 0;
    }
  }
}

int main() {
  char opt;
  cin >> opt >> N >> M;
  if(N < M) cout << "n must be bigger than m!" << endl;
  else if(N > 10) cout << "n must be smaller than 12!" << endl;
  else if(opt == 'C') dfsC(N, M);
  else if(opt == 'A') dfsA(N, M);
  else cout << "option '" << opt << "' is invalid!" << endl;
  return 0;
}