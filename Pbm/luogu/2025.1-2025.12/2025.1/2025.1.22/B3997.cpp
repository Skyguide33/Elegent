//2025/1/22
#include <iostream>
using namespace std;

int main() {
  int count = 0;
  string input;
  cin >> input;
  for(unsigned i = 1; input.length(); i++) {
    string t(input, 0, i);
    //cout << "t= " << t << endl;
    bool res = 1;
    for(unsigned j = 0; j < t.length(); j++) {
      if(t[j] != t[t.length()-j-1]) {
        res = 0;
        break;
      }
    }
    count += res;
    //cout << "count= " << count << endl;
    input = input.substr((i<input.length()?i:input.length()));
  }
  cout << count << endl;
  return 0;
}