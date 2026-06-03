//2025/1/18
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int a[N+1] = {0};
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      if(j % i == 0) {
        if(a[j] == 0) a[j] = 1;
        else a[j] = 0;
      }
    }
  }
  for(int i = 1; i <= N; i++) {
    if(a[i] == 1) cout << i << ' ';
  }
  return 0;
}