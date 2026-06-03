#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  char a[11][11], b[11][11];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> b[i];
  }

  bool same = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(a[i][j] != b[j][n-1-i]) {
        same = 0;
        break;
      }
    }
    if(!same) break;
  }
  if(same) {
    cout << '1' << endl;
    return 0;
  }

  same = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(a[i][j] != b[n-1-i][n-1-j]) {
        same = 0;
        break;
      }
    }
    if(!same) break;
  }
  if(same) {
    cout << '2' << endl;
    return 0;
  }

  same = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(a[i][j] != b[n-1-j][i]) {
        same = 0;
        break;
      }
    }
    if(!same) break;
  }
  if(same) {
    cout << '3' << endl;
    return 0;
  }
  
  same = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(a[i][j] != b[i][n-1-j]) {
        same = 0;
        break;
      }
    }
    if(!same) break;
  }
  if(same) {
    cout << '4' << endl;
    return 0;
  }

  same = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(a[i][j] != b[n-1-j][n-1-i]) {
        same = 0;
        break;
      }
    }
    if(!same) break;
  }
  if(same) {
    cout << '5' << endl;
    return 0;
  }

  same = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(a[i][j] != b[n-1-i][j]) {
        same = 0;
        break;
      }
    }
    if(!same) break;
  }
  if(same) {
    cout << '5' << endl;
    return 0;
  }

  same = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(a[i][j] != b[j][i]) {
        same = 0;
        break;
      }
    }
    if(!same) break;
  }
  if(same) {
    cout << '5' << endl;
    return 0;
  }

  same = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(a[i][j] != b[i][j]) {
        same = 0;
        break;
      }
    }
    if(!same) break;
  }
  if(same) {
    cout << '6' << endl;
    return 0;
  }
  cout << '7' << endl;
  return 0;
}