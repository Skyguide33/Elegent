#include<bits/stdc++.h>
using namespace std;
#define int long long

int p[32];

signed main(){
        p[0]=1;
        for(int i=1;i<32;i++)p[i]=p[i-1]*2;
        int n;
        cin>>n;
       vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
      vector<int>st1(32),st0(32),ts1(32),ts0(32);
    for(int i=0;i<n;i++){
        int op=a[i];
        int cnt=0;
        for(int j=0;j<32;j++){
            if(op%2){
                if(cnt%2==0)st1[j]++;
                else ts1[j]++;
                cnt++;
            }
            else{
                if(cnt%2==0)st0[j]++;
                else ts0[j]++;
            }
            op/=2; 
        }
    }
        int ans=0;
        for(int i=0;i<32;i++){
            ans+=st1[i]*st0[i]*p[i];
            ans+=ts1[i]*ts0[i]*p[i];
        }
        cout<<ans<<endl;
  
}