#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(n%2==1)cout<<"YES"<<endl;
        else if(n==2){
            if(a[0]==a[1])cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else {
            int sum=1;
            for(int i=0;i<n-1;i++){
                sum*=a[i];
            }
    
            int ans=1;
        if(sum%a[n-1])ans=0;
            sum/=a[n-1];
            int op=sqrt(sum);
            if(op*op!=sum)ans=0;
            if(ans)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}