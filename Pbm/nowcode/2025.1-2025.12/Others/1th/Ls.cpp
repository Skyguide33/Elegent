#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<long long> a(1 + n);
        vector<long long>b;
        multiset<long long>s;
        for(long long i=1;i<=n;i++){
            cin>>a[i];
            
            s.insert(a[i]);
        }
        b=a;
       sort(b.begin(),b.end());
        long long mid=b[(n+1)/2];
        long long xh=1;
        for(long long i=(n+1)/2-1;i>=1;i--){
            if(b[i]!=mid)break;
            xh++;
        }
        long long p,v,ss,tt;
          long long cmid=s.count(mid);
        while(q--){
            cin>>p>>v;
           ss=a[p];
            auto ii=s.find(ss);
          s.erase(ii);
            a[p]+=v;
             tt=a[p];
          s.insert(tt);
          if(ss==mid)cmid--;
            if(tt==mid)cmid++;
            if (mid > ss && tt >= mid) {
              xh++;
            }
             if(xh>cmid){
                    xh=1;
                    auto it=s.upper_bound(mid);
                    mid=*it;
                 cmid=s.count(mid);
                }
                long long ans = (1 + n) / 2;
                if (xh < cmid) {
                  ans -= xh;
                }
            cout<<ans<<endl;
        }
        
    }
}