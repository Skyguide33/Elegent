//2025/2/28
#include <iostream>
using namespace std;

int main() {
  int ans = 1;
  string s1, s2;
  int s2ap[26];
  cin >> s1 >> s2;
  for(int i = 0; i < s2.length(); i++) s2ap[s2.at(i)-'a'] = i;
  for(int i = 0; i < s1.length()-1; i++) {
    if(s2ap[s1.at(i)-'a'] == s2ap[s1.at(i+1)-'a']+1) ans <<= 1;
  }
  cout << ans << endl;
  return 0;
}