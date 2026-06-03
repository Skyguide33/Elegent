//2025/11/10
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 3000005

int son[N][26], cnt;
int isend[N];
int topo[26][26], in[26], tail, res[30005], num;

vector<string> ss(N);

void Insert(int idx) {
  int p = 0;
  const string &s = ss[idx];
  for(int i = 0; s[i]; ++i) {
    int ch = s[i]-'a';
    if(!son[p][ch]) son[p][ch] = ++cnt;
    p = son[p][ch];
  }
  isend[p] = idx;
}

void check(int idx) {
  memset(topo, 0, sizeof(topo));
  memset(in, 0, sizeof(in));
  const string &s = ss[idx];
  int p = 0;
  for(int i = 0; s[i]; ++i) {
    int ch = s[i]-'a';
    for(int j = 0; j < 26; ++j) {
      if(j != ch && son[p][j] && !topo[ch][j]) {
        topo[ch][j] = 1;
        ++in[j];
      }
    }
    p = son[p][ch];
    if(isend[p]) break;
  }
  if(res[isend[p]] != -1) return;
  queue<int> q;
  for(int i = 0; i < 26; ++i) {
    if(in[i] == 0) q.push(i);
  }
  while(!q.empty()) {
    int now = q.front(); q.pop();
    in[now] = -1;
    for(int i = 0; i < 26; ++i) {
      if(topo[now][i] && --in[i] == 0) q.push(i);
    }
  }
  for(int i = 0; i < 26; ++i) {
    if(in[i] != -1) {
      res[isend[p]] = 0;
      return;
    }
  }
  ++num;
  res[isend[p]] = 1;
  return;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  memset(res, -1, sizeof(res));
  
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> ss[i];
    Insert(i);
  }
  for(int i = 1; i <= n; ++i) check(i);
  cout << num << endl;
  for(int i = 1; i <= n; ++i) {
    if(res[i] == 1) cout << ss[i] << endl;
  }
  return 0;
}