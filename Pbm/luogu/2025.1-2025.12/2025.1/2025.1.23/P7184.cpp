//2025/1/23
#include <iostream>
using namespace std;

int Svens(string *fnd, string Sven, int now, int fnum) {
  int S = 0, R = 0, P = 0;
  for(int i = 0; i < fnum; i++) {
    if(fnd[i][now] == 'S') S++;
    else if(fnd[i][now] == 'R') R++;
    else if(fnd[i][now] == 'P') P++;
  }
  if(Sven[now] == 'S') return S + 2*P;
  else if(Sven[now] == 'R') return R + 2*S;
  return P + 2*R;
}
int Maxs(string *fnd, string Sven, int now, int fnum) {
  int S = 0, R = 0, P = 0, c1, c2, c3;
  for(int i = 0; i < fnum; i++) {
    if(fnd[i][now] == 'S') S++;
    else if(fnd[i][now] == 'R') R++;
    else if(fnd[i][now] == 'P') P++;
  }
  c1 = S + 2*P;
  c2 = R + 2*S;
  c3 = P + 2*R;
  if(c1 < c2) c1 = c2;
  if(c1 < c3) c1 = c3;
  return c1;
}
int main() {
  int r, fnum, Ss = 0, Ms = 0;
  cin >> r;
  string Sven;
  cin >> Sven;
  cin >> fnum;
  string fnd[fnum];
  for(int i = 0; i < fnum; i++) cin >> fnd[i];
  for(int i = 0; i < r; i++) {
    Ss += Svens(fnd, Sven, i, fnum);
    Ms += Maxs(fnd, Sven, i, fnum);
  }
  cout << Ss << endl << Ms << endl;
  return 0;
}