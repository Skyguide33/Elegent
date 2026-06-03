//2025/3/8
#include <bits/stdc++.h>
using namespace std;

typedef struct{
  string v;
  int id;
}can;

bool cmp(can a, can b) {
  if(a.v.size() == b.v.size()) return a.v < b.v;
  return a.v.size() < b.v.size();
}

int main() {
  int n;
  cin >> n;
  can C[25];
  for(int i = 0; i < n; i++) {
    cin >> C[i].v;
    C[i].id = i+1;
  }
  sort(C, C+n, cmp);
  cout << C[n-1].id << endl << C[n-1].v << endl;

  return 0;
}