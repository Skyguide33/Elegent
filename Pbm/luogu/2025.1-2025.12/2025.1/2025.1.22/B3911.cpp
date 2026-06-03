//2025/1/22
#include <iostream>
using namespace std;

int main() {
  int N, k;
  cin >> N >> k;
  string name[N];
  int var[N];
  for(int i = 0; i < N; i++) {
    cin >> name[i] >> var[i];
  }
  cin.get();
  while(k--) {
    string temp, t;
    getline(cin, temp);
    int a = temp.find("{");
    while(a != -1) {
      int b = temp.find("}");
      t = temp.substr(a+1, b-a-1);
      int j = 0;
      for(; j < N; j++) {
        if(t == name[j]) break;
      }
      temp.replace(a, b-a+1, to_string(var[j]));
      a = temp.find("{");
    }
    cout << temp << endl;
    //printf("%s\n", temp.c_str());
  }
  return 0;
}