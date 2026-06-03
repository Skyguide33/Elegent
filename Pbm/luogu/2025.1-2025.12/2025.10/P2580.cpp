//2025/10/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Node {
  bool repeat, isend;
  int son[26];
} t[5000005];
int cnt = 1;

void Insert(char *s) {
  int now = 0;
  for(int i = 0; s[i]; ++i) {
    int ch = s[i]-'a';
    if(t[now].son[ch] == 0) t[now].son[ch] = cnt++;
    now = t[now].son[ch];
  }
  t[now].isend = true;
}

int Find(char *s) {
  int now = 0;
  for(int i = 0; s[i]; ++i) {
    int ch = s[i]-'a';
    if(t[now].son[ch] == 0) return 0;
    now = t[now].son[ch];
  }
  if(t[now].isend == false) return 0;
  else if(t[now].repeat == 1) return 2;
  else {
    t[now].repeat = 1;
    return 1;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  char s[51];
  int n; cin >> n;
  while(n--) {
    cin >> s;
    Insert(s);
  }
  int m; cin >> m;
  while(m--) {
    cin >> s;
    int r = Find(s);
    if(r == 1) cout << "OK" << endl;
    else if(r == 2) cout << "REPEAT" << endl;
    else cout << "WRONG" << endl;
  }
  return 0;
}