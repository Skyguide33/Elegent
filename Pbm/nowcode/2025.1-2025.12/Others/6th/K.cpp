#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>s(N);
        vector<int>a(n+1);
        int mx=0,mi=1e9;
        for(int i=1;i<=n;i++){
         cin>>a[i];
            mx=max(mx,a[i]);
            mi=min(mi,a[i]);
        s[a[i]]++;
        }
        if(s[a[1]]==n){
            cout<<0<<endl;
            continue;
        }
        int cmi=0;
        int ans=0;
        for(int i=mx;i>=1;i--){
            if(ans)break;
            int mod=mi%i;
            if(mod){
                int op=0;
                for(int j=0;j*i+mod<=mx;j++){
                    op+=s[j*i+mod];
                }
                  for(int j=1;j*i<=mx;j++){
                    op+=s[j*i];
                }
                if(op!=n)continue;
               ans=i;
                int o1=0,o2=0;
                for(int j=1;j<=n;j++){
                    if(!o1&&a[j]%i)o1=j;
                    else if(!o2&&o1&&a[j]%i==0)o2=j;
                    else if(o1&&o2&&a[j]%i){
                        ans=0;
                        break;
                    }
                }
                
            }
            else{
                ans=i;
                int o1=0;
                for(int j=1;j<=n;j++){
                    if(!o1&&a[j]%i)o1=a[j]%i;
                    else if(o1&&a[j]%i&&o1!=a[j]%i){
                        ans=0;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}