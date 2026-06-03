//2026/3/18
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int k; cin >> k;
  bool flag = 0;
  for(int i = 10000; i <= 30000; ++i) {
    string s = to_string(i);
    string sub1 = s.substr(0, 3);
    string sub2 = s.substr(1, 3);
    string sub3 = s.substr(2, 3);
    int num1 = stoi(sub1);
    int num2 = stoi(sub2);
    int num3 = stoi(sub3);
    if(num1%k == 0 && num2%k == 0 && num3%k == 0) {
      cout << i << endl;
      flag = 1;
    }
  }
  if(!flag) cout << "No" << endl;
  return 0;
}