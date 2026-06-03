//2025/1/23
#include <iostream>
using namespace std;

int arr[3][3];

int main() {
  char num;
  bool a = 1;
  while(cin >> num) {
    *(*arr + num - 1 - '0') = (a?1:2);
    a = (a?0:1);
  }
  for(int i = 0; i < 3; i++) {
    if(arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2]) {
      if(arr[i][0] == 1) cout << "xiaoa wins." << endl;
      else cout << "uim wins." << endl;
      return 0;
    }
  }
  for(int j = 0; j < 3; j++) {
    if(arr[0][j] == arr[1][j] && arr[0][j] == arr[2][j]) {
      if(arr[0][j] == 1) cout << "xiaoa wins." << endl;
      else cout << "uim wins." << endl;
      return 0;
    }
  }
  if(arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2]) {
    if(arr[0][0] == 1) cout << "xiaoa wins." << endl;
    else cout << "uim wins." << endl;
    return 0;
  }
  if(arr[0][2] == arr[1][1] && arr[0][0] == arr[2][0]) {
    if(arr[0][2] == 1) cout << "xiaoa wins." << endl;
    else cout << "uim wins." << endl;
    return 0;
  }
  cout << "drew." << endl;
  return 0;
}