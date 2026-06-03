
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int h;
int a[500005], b[500005],st[500005];
 map<int,int>mp;
void dfs(int s,int x,int si){
    st[x]=1;
    si++;
    if(s==x){
      if(si>=2)h++;
      return;
    }
    else{
      dfs(s,mp[x],si);
    }
}

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) cin >> b[i];
  for(int i = 1; i <= n; ++i) st[i]=0;
  mp.clear();
  h=0;
  for(int i=1;i<=n;i++)mp[a[i]]=b[i];
  int s=0;
  for(int i=1;i<=n;i++)if(a[i]!=b[i])s++;
  for(int i=1;i<=n;i++){
    if(!st[a[i]]){
      st[a[i]]=1;
      dfs(a[i],b[i],0);
    }
 }
 s-=h;
 s%=2;
  cout << (s? 'A': 'B');
  char t; int l, r, d;
  for(int i = 1; i <= n-1; ++i) {
    cin >> t >> l >> r >> d;
    if((r-l+1+d) % 2) s ^= 1; // (区间长度+左移次数)为奇数时，赢家翻转
    cout << (s? 'A': 'B');
  }
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}