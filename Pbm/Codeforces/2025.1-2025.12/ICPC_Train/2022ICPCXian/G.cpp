//2025/11/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

string ss[100005];
int avail[100005];

bool cmp(const string &x, const string &y) { 
  if(x.length() == y.length()) return x < y;
  else return x.length() < y.length();
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> ss[i];
  sort(ss+1, ss+n+1, cmp);
  int maxlen = 0;
  for(int i = 1; i <= n; ++i) {
    if(ss[i].length() == 1) {
      avail[i] = 1;
      maxlen = max(maxlen, 1);
    } else {
      string t1 = ss[i].substr(0, ss[i].length()-1);
      string t2 = ss[i].substr(1);
      int pos1 = lower_bound(ss+1, ss+i, t1, cmp)-ss;
      int pos2 = lower_bound(ss+1, ss+i, t2, cmp)-ss;
      if(ss[pos1] == t1 && avail[pos1] && ss[pos2] == t2 && avail[pos2]) {
        avail[i] = 1;
        maxlen = max(maxlen, int(ss[i].length()));
      }
    }
  }
  cout << maxlen << endl;
  return 0;
}