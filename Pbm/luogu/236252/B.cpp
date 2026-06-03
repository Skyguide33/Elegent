//2026/2/8
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define endl '\n'
#define MOD 1000000007

string s;
map<int, int> mp;
tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ch_tr;

ll ans;

void get_res(int l, int r) {
  int temp = 1, num = 0, pos = 0;
  for(int i = l; i <= r; ++i) {
    if(isdigit(s[i])) {
      if(!pos) pos = i;
      num = (10ll*num+s[i]-'0')%MOD;
    } else {
      temp = 1ll*temp*num%MOD;
      num = 0;
      if(s[i] != '*') {
        ans = (1ll*ans-mp[pos]+MOD)%MOD;
        mp[pos] = temp;
        ans = (1ll*ans+temp+MOD)%MOD;
        temp = (s[i] != '-'? 1: MOD-1);
        pos = 0;
      }
    }
  }
  temp = 1ll*temp*num%MOD;
  ans = (1ll*ans-mp[pos]+MOD)%MOD;
  mp[pos] = temp;
  ans = (1ll*ans+temp+MOD)%MOD;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> s;
  int len = s.length();
  s = '+'+s;
  for(int i = 1; i <= len; ++i) {
    if(!isdigit(s[i])) ch_tr.insert(i);
  }
  mp[len+2] = 0;
  get_res(1, len);
  cout << ans << endl;
  int q; cin >> q;
  while(q--) {
    int k, l, r; char c; cin >> k >> c;
    k = *ch_tr.find_by_order(k-1);
    if(c != '*' && s[k] == '*') {
      s[k] = c;
      auto it = mp.upper_bound(k);
      r = it->first-2;
      l = (--it)->first-1;
      get_res(l, r);
      cout << ans << endl;
    }
  }
  return 0;
}