//2025/2/8
#include <iostream>
using namespace std;

struct Char {
  char name[11];
  char A;
  long long skill;
};

int main() {
  int S, H, s = 0, h = 0;
  cin >> S >> H;
  Char t, Ss[S], Hs[H];
  for(int i = 0; i < S+H; i++) {
    cin >> t.name >> t.A >> t.skill;
    if(t.A == 'S') {
      Ss[s] = t;
      s++;
    }
    else {
      Hs[h] = t;
      h++;
    }
  }
  
  int max_s = 0;
  long long max_skill = 0;
  for(int i = 0; i < 2; i++) {
    max_s = 0, max_skill = 0;
    for(int i = 0; i < H; i++) {
      if(Hs[i].skill > max_skill) {
        max_skill = Hs[i].skill;
        max_s = i;
      }
    }
    Hs[max_s].skill = 0;
  }
  max_s = 0, max_skill = 0;
  for(int i = 0; i < H; i++) {
    if(Hs[i].skill > max_skill) {
      max_skill = Hs[i].skill;
      max_s = i;
    }
  }
  cout << Hs[max_s].name << endl;


  for(int i = 0; i < 5; i++) {
    max_s = 0, max_skill = 0;
    for(int i = 0; i < S; i++) {
      if(Ss[i].skill > max_skill) {
        max_skill = Ss[i].skill;
        max_s = i;
      }
    }
    Ss[max_s].skill = 0;
  }
  for(int i = 0; i < 4; i++) {
    max_s = 0, max_skill = 0;
    for(int i = 0; i < S; i++) {
      if(Ss[i].skill > max_skill) {
        max_skill = Ss[i].skill;
        max_s = i;
      }
    }
    cout << Ss[max_s].name << endl;
    Ss[max_s].skill = 0;
  }
  return 0;
}