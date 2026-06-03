//2025/5/23
#include <bits/stdc++.h>
using namespace std;

char s[9];

bool isprime(char* c, int len) {
  int num = 0; 
  for(int i = len-1; i >= 0; --i) num = num*10+(c[i]-'0');
  if(num == 1) return 0;
  for(int i = 2; i*i <= num; ++i) {
    if(num % i == 0) return 0;
  }
  return 1;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> s;
  dfs()
  return 0;
}