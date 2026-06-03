//2025/11/19
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int a[3]; 
  for(int i = 0; i < 3; ++i) cin >> a[i];
  sort(a, a+3);
  if(a[2]-a[0] >=10) {
    cout << "check again" << endl;
  } else {
    cout << "final " << a[1] << endl;
  }
  return 0;
}