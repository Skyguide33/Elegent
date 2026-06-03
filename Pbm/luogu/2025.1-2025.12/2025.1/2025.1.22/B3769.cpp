//2025/1/22
#include <iostream>
using namespace std;

int main() {
  string s, t;
  int q;
  cin >> s >> t >> q;
  //cout << s << ' ' << t << ' ' << q << endl;
  for(int i = 0; i < q; i++) {
    int s1, s2, t1, t2;
    cin >> s1 >> s2 >> t1 >> t2;
    string sm(s, s1-1, s2-s1+1);
    string tm(t, t1-1, t2-t1+1);
    //cout << sm << endl << tm << endl;
    bool equal = 1;
    for(unsigned j = 0; j < sm.length()+1 && j < tm.length()+1; j++) {
      if(sm[j] > tm[j]) {
        cout << "erfusuer" << endl;
        equal = 0;
        break;
      }
      else if(sm[j] < tm[j]) {
        cout << "yifusuyi" << endl;
        equal = 0;
        break;
      }
    }
    if(equal) cout << "ovo" << endl;
  }
  return 0;
}