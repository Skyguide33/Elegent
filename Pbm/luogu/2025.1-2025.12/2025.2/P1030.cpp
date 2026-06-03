// //2025/2/23
#include <iostream>
using namespace std;

void beford(string inord, string postord) {
  if(inord.size() > 0) {
    char ch = postord.at(postord.size()-1);
    cout << ch;
    int pos = inord.find(ch);
    beford(inord.substr(0, pos), postord.substr(0, pos));
    beford(inord.substr(pos+1), postord.substr(pos, postord.size()-pos-1));
  }
}
int main() {
  string inord, postord;
  cin >> inord >> postord;
  beford(inord, postord);
  cout << endl;
  return 0;
}