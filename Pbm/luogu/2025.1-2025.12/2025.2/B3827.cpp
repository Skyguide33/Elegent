//2025/2/9
#include <iostream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  double Score[n], sum, t;
  for(int i = 0; i < n; i++) {
    sum = 0;
    for(int j = 0; j < k; j++) {
      cin >> t;
      sum += t;
    }
    Score[i] = sum / k; 
  }
  for(int i = 0 ; i < 2; i++) {
    int MaxPos = 0; 
    double MaxScr = 0;
    for(int j = 0; j < n; j++) {
      if(Score[j] > MaxScr) {
        MaxPos = j;
        MaxScr = Score[j];
      }
    }
    cout << MaxPos+1 << endl;
    Score[MaxPos] = 0;
  }
  return 0;
}