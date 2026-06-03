//2025/3/24
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  int arr[n], ab[n];
  for(int i = 0; i < n; i++) cin >> arr[i];
  for(int i = 1; i < n; i++) {
    ab[i] = abs(arr[i]-arr[i-1]);
  }
  sort(ab+1, ab+n);
  //for(int i = 1; i < n; i++) cout << ab[i] << ' ';
  for(int i = 2; i <  n; i++) {
    if(ab[i] - ab[i-1] >= 2) {
      cout << "Not jolly" << endl;
      return 0;
    }
  }
  cout << "Jolly" << endl;
  return 0;
}