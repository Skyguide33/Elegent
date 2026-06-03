#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long qmi(long long a,long long b){
long long ans=1;
while(b){
  if(b%2){
    ans*=a;
    ans%=mod;
  }
  a*=a;
  a%=mod;
  b/=2;
}
return ans;
}
int main(){
  int n;
  cin>>n;
 int a;
 int si=0;
 int fr=0;
 vector<int>mp(n+2);
  priority_queue<int,vector<int>,greater<int>>p;
  long long gl=1;
  for(int i=0;i<n*2;i++){
     cin>>a;
     if(a!=-1){
      si++;
      mp[a]++;
      p.push(a);
     }
     else{
      int op=p.top();
      p.pop();
    
      if(op<fr){
        gl=0;
      }
      fr=op;
      gl*=mp[op];
      gl%=mod;
      gl*=qmi(si,mod-2);
      gl%=mod;
      si--;
      mp[op]--;

     }
  }
  cout<<gl<<endl;

}