#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>st(N);
vector<int>tr[N];
int ans=0;
int pd=0;
void dfs(int x,int f){
  if(pd == 2){
    ans=0;
    return;
  }
  int op=0;
  for(int i = 0; i < tr[x].size(); i++){
    if(st[tr[x][i]] < st[x]/2){
      op++;
      ans=0;
      if(f == 0)pd++;
      dfs(tr[x][i],1);

    } else{
      ans++;
      dfs(tr[x][i],0);
    }
  }
  if(op>=2){
    ans=0;
    pd=2;
    return;
  }

}
int main(){
  int t;
  cin >>  t;
  while(t--){
    int n;
    cin >> n;
    st.clear();
    int mx=0,d=0;
    for(int i=1;i<=n;i++){
      tr[i].clear();
      cin>>st[i];
      if(st[i]>mx){
        mx=st[i];
        d=i;
      }
    }
    for(int i=1;i<n;i++){
      int l,r;
      cin>>l>>r;
      tr[l].push_back(r);
      tr[r].push_back(l);
    }
    dfs(d,0);
    cout<<ans<<endl;
  }
}