#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
 t=1;
  while(t--){
    long long n,m;
    cin>>n>>m;
    vector<long long>a(m);
    for(int i=0;i<m;i++){
      cin>>a[i];
    }
   // sort(a.begin(),a.end());
    for(int i=0;i<m;i++){
      cout<<a[i]<<endl;
    }
    long long ans=0;
    long long op=0;
    long long len=0;
    len=a[m-1];
    op=1;
    for(int i=m-2;i>=0;i--){
      
        if(pow(op+1,4)-pow(op,4)<=a[i]){
          op++;
        }
        else{
          ans+=pow(op,4)+len;
          len=a[i];
          op=1;
        }

    }
    ans+=pow(op,4)+len;
    cout<<ans<<endl;
    
  }
}