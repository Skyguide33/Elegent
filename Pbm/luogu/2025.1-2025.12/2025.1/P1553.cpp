//2025/1/25
#include <iostream>
using namespace std;

string rev(string num, bool fl) {
  for(unsigned i = 0; i < num.length()/2; i++) {
    char t = num[i];
    num[i] = num[num.length()-i-1];
    num[num.length()-i-1] = t;
  }
  while(num.length() > 1 && num.front() == '0') num.erase(num.begin());
  if(fl) {
    while(num.length() > 1 && num.back() == '0') num.erase(num.end()-1);
  } 
  while(num.length() > 1 && num.front() == '0') num.erase(num.begin());
  return num;
}
int main() {
  string s;
  cin >> s;
  unsigned sympos = 0;
  while(s[sympos] != '\0' && s[sympos] != '.' && s[sympos] != '/' && s[sympos] != '%') sympos++;
  //cout << "sympos= " << sympos << endl;
  if(sympos == s.length()) cout << rev(s.substr(0, sympos), 0) << endl;
  else if(s[sympos] == '.')  cout << rev(s.substr(0, sympos), 0) << s[sympos] << rev(s.substr(sympos+1), 1) << endl;
  else cout << rev(s.substr(0, sympos), 0) << s[sympos] << rev(s.substr(sympos+1), 0) << endl;
  return 0;
}