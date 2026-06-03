//2025/3/8
#include <iostream>
using namespace std;

int T[1000005];

int main() {
  int n, sum = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &T[i]);
  for(int gap = n/2; gap; gap /= 2) {
    for(int i = gap; i < n; i++) {
      int key = T[i];
      int j = i-1;
      while(j-gap+1 >= 0 && T[j-gap+1] > key) {
        T[j+1] = T[j-gap+1];
        j -= gap;
      }
      T[j+1] = key;
    }
  }
  for(int i = 1; i < n; i++) {
    T[i] += T[i-1];
  }
  for(int i = 0; i < n; i++) {
    sum += T[i];
  }
  cout.precision(2);
  double avg = double(sum) / double(n);
  cout << endl << fixed << avg << endl;
  return 0;
}