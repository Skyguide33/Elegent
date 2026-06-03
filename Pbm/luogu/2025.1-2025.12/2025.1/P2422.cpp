//2025/1/26
#include <bits/stdc++.h>
using namespace std;

int Ns[1000005];
int s[1000005];

int main() {
  int N, ans = 0, tail = 0;
  deque<int>mi;
  mi.push_back(0);
  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> Ns[i];
    s[i] = s[i-1] + Ns[i];
    if(mi.size() > 1 && s[mi.back()] > s[i]) {
      for(int j = 0; j < mi.size()-1; j++) {
        int t = s[j+1] - s[j];
        if(ans < t) ans = t;
      }
    }
    mi.push_back(i);
  }
  return 0;
}