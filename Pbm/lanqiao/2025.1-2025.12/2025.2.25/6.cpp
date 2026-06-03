#include <iostream>
using namespace std;

int main() {
  int max = 0, maxi, maxlen, len = 1;
  string S = "ANQNANBNQNANQNQNBNINQNQNANQNINANQNANBNQNANQNQNBNBNQNQNANQNINANQNANBNQNANQNQNBNINQNQNANQNINBNQNANBNQN";
  while(len <= 10) {
    for(int i = 0; i+len-1 < S.length(); i++) {
      int cnt = 0;
      for(int j = 0; j+len-1 < S.length(); j++) {
        if(S.substr(i,len) == S.substr(j,len)) {
          cnt++;
        }
      }
      if(max < cnt*len) {
        max = cnt*len;
        maxi = i;
        maxlen = len;
        cout << "cnt=" << cnt << ", len=" << len << ", i=" << i << endl;
        cout << S.substr(maxi, maxlen) << endl;
      }
    }
    len++;
  }
  return 0;
}