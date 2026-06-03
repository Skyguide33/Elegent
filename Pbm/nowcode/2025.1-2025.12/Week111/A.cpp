//2025/9/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int a[3]; 
  for(int i = 0; i < 3; ++i) cin >> a[i];
  if(a[0]+1 == a[1] && a[1]+1 == a[2]) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}