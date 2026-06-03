#include<bits/stdc++.h>
using namespace std;
const long long mod =998244353;
const int N=5e5+10;
long long a[N],st[N];
vector<long long>h;
long long js1=0,js2=0;
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
void dfs(long long x,long long sum){
    st[x]=1;
    sum++;
    if(st[a[x]]){
     if(sum%2){
         if(!js1)js1=sum;
         else js2=sum;
     }
      else h.push_back(sum);
        return;
    }
    else dfs(a[x],sum);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        h.clear();
        js1=0,js2=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            st[i]=0;
        }
        for(int i=1;i<=n;i++){
            if(st[i])continue;
            
            dfs(i,0);
        }
       long long ans=0;
        if(js1){ 
            ans=1;
            ans=js1*js2;
            ans%=mod;
           ans*=qmi(2,h.size());
            ans%=mod;
        }
        else{ans=0;
            for(int i=0;i<h.size();i++){
                long long tp=n*n/4;
                tp*=qmi(2,h.size()-1);
                ans+=tp;
                ans%=mod;
            }
        }
        cout<<ans<<endl;
    }
}