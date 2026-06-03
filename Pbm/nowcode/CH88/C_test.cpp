//2026/5/15
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int cnt(int flr, int cil, int len) {
  int res = 0;
  for(int i = 1; i <= pow(10, len)-1; ++i) {
    // cout << "i=" << i << endl;
    vector<int> a(1, 0);
    int tt = i;
    bool flag = 1;
    for(int i = 1; i <= len; ++i) {
      int num = tt%10;
      if(num < flr || num > cil) {
        flag = 0;
        break;
      }
      a.push_back(num);
      tt /= 10;
    }
    if(!flag) continue;
    reverse(a.begin()+1, a.end());
    flag = 1;
    for(int i = 1; i <= len; ++i) {
      if(a[i-1] > a[i]) {
        flag = 0;
        break;
      }
    }
    if(!flag) continue;
    flag = 1;
    for(int i = 1; i <= len; ++i) {
      if(a[i] != a[a[i]]) {
        flag = 0;
        break;
      }
    }
    if(flag) {
      ++res;
      cout << i << ' ';
    }
  }
  cout << endl;
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cout << cnt(1, 5, 2) << endl;
  return 0;
}