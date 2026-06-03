//2025/1/20
#include <iostream>
#include <cstring>
using namespace std;

int main() {
  char a[50], b[50];
  cin >> a >> b;

  if(strstr(a, b)) cout << b << " is substring of " << a << endl;
  else if(strstr(b, a)) cout << a << " is substring of " << b << endl;
  else cout << "No substring" << endl;
  // cin >> a >> b;
  // // cin.getline(a, 50);
  // // cin.getline(b, 50);
  // // cout << "a:" << a << "/end" << endl;
  // // cout << "b:" << b << "/end" << endl;
  // int lena = 0, lenb = 0;
  // while(a[lena]) lena++;
  // while(b[lenb]) lenb++;
  // // cout << "lena= " << lena << endl;
  // // cout << "lenb= " << lenb << endl;
  // bool sub = 0;
  // if(lena < lenb) {
  //   char first = a[0];
  //   char end = a[lena-1];
  //   for(int i = 0; i <= lenb-lena; i++) {
  //     if(b[i] == first && b[i+lena-1] == end) {
  //       int j = 0;
  //       for(; j < lena; j++) {
  //         if(a[j] != b[i+j]) break;
  //       }
  //       if(j == lena) sub = 1;
  //     }
  //   }
  //   if(sub) cout << a << " is substring of " << b << endl;
  //   else cout << "No substring" << endl;
  // } 
  // else {
  //   char first = b[0];
  //   char end = b[lenb-1];
  //   for(int i = 0; i <= lena-lenb; i++) {
  //     if(a[i] == first && a[i+lenb-1] == end) {
  //       int j = 0;
  //       for(; j < lenb; j++) {
  //         if(b[j] != a[i+j]) break;
  //       }
  //       if(j == lenb) sub = 1;
  //     }
  //   }
    // if(sub) cout << b << " is substring of " << a << endl;
    // else cout << "No substring" << endl;
  //}
  return 0;
}