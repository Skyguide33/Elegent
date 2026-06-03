//2025/11/9
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 1000005

int son[N][26];
int cnt[N];
ll res[26][26], minans, idx;

void Insert(const string &s) {
  int p = 0;
  for(int i = 0; s[i]; ++i) {
    int ch = s[i]-'a';
    if(!son[p][ch]) son[p][ch] = ++idx;
    for(int i = 0; i < 26; ++i) {
      res[i][ch] += cnt[son[p][i]];
    }
    p = son[p][ch];
    ++cnt[p];
  }
  for(int i = 0; i < 26; ++i) minans += cnt[son[p][i]];
}

ll getans(const string &s) {
  ll ans = 0;
  for(int i = 0; i < 26; ++i) {
    for(int j = i+1; j < 26; ++j) {
      ans += res[s[j]-'a'][s[i]-'a'];
    }
  }
  return ans;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, q; cin >> n >> q;
  string s;
  while(n--) {
    cin >> s;
    Insert(s);
  }
  while(q--) {
    cin >> s;
    cout << minans+getans(s) << endl;
  }
  return 0;
}