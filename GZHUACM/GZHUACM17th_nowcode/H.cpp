//2026/3/27
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string s; getline(cin, s);
  for(int i = 0; s[i]; ++i) {
    if(s[i] == '4') cout << 'a';
    else if(s[i] == '6') cout << 'b';
    else if(s[i] == '3') cout << 'e';
    else if(s[i] == '9') cout << 'g';
    else if(s[i] == '1') cout << 'l';
    else if(s[i] == '0') cout << 'o';
    else if(s[i] == '5') cout << 's';
    else if(s[i] == '7') cout << 't';
    else if(s[i] == '2') cout << 'z';
    else cout << s[i];
  }
  cout << endl;
  return 0;
}