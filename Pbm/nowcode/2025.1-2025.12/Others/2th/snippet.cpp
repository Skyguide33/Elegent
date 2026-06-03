#include<bits/stdc++.h>
using namespace std;

#define M_PI 3.14159265358

int main(){
    int t;
    cin>>t;
    while(t--){
        double n,x,y;
        cin>>n>>x>>y;
        vector<pair<double,double>>p(n);
        for(int i=0;i<n;i++){
            cin>>p[i].first>>p[i].second;
        }
        int in=1;
        double mx=0;
        for(int i=0;i<n-1;i++){
            double s1=sqrt((x-p[i].first)*(x-p[i].first)+(y-p[i].second)*(y-p[i].second));
            double s2=sqrt((x-p[i+1].first)*(x-p[i+1].first)+(y-p[i+1].second)*(y-p[i+1].second));
            mx=max(mx,s1);
            mx=max(mx,s2);
            double cj=((p[i].first - x)*(p[i+1].second - y) - (p[i+1].first - x)*(p[i].second - y));
            if(cj<0){
                in=0;
                
            }
        }
     
        double ans=0;
      
        if(in==0)ans=2*M_PI;
        else{
              vector<pair<double,double>>zc;
            for(int i=0;i<n;i++){
                 double s1=sqrt((x-p[i].first)*(x-p[i].first)+(y-p[i].second)*(y-p[i].second));
                if(s1-mx<1e-15&&mx-s1<1e-15){
                    zc.push_back(p[i]);
                }
            }
            zc.push_back(zc[0]);
            double amx=0;
              for(int i=0;i<zc.size()-1;i++){
            double s1=sqrt((x-zc[i].first)*(x-zc[i].first)+(y-zc[i].second)*(y-zc[i].second));
            double s2=sqrt((x-zc[i+1].first)*(x-zc[i+1].first)+(y-zc[i+1].second)*(y-zc[i+1].second));
          double dot=((zc[i].first-x)*(zc[i+1].first-x)+(zc[i].second-y)*(zc[i+1].second-y));
         double xj=((zc[i].first - x)*(zc[i+1].second - y) - (zc[i+1].first - x)*(zc[i].second - y));
                  double ta=xj/dot;
                 double xi=xj/dot;
                  xi=atan2(xj,dot);
                 if(xi<0)xi+=2*M_PI;
                  amx=max(amx,xi);
                  if(zc.size()==2)amx=2*M_PI;
        
        }
            
            ans=amx;
            
        }
        cout<<fixed<<setprecision(15)<<ans<<endl;
    }
}