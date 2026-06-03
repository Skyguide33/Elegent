//2025/11/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
 ll x,y,k;
 bool check(ll a){
  for(int i=0;i<x;i++)a-=a/y;
  if(a>=k)return true;
  else return false;
 }
void solve() {
  
   cin>>x>>y>>k;
   ll l=1,r=1e12+1,mid;
   while(l<r){
    mid=(l+r)/2;
    if(check(mid))r=mid;
    else l=mid+1;
   }
   if(l==1e12+1)cout<<-1<<endl;
  else  cout<<l<<endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}