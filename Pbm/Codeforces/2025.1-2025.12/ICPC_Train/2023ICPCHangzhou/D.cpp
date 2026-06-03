#include<bits/stdc++.h>
using namespace std;
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(2*n+1);
        for(int i=2;i<2*n;i++){
            a[i]=2;
            if(i%2)a[i]=-1;
        } 
        for(int x=1;x<=2*n;x++){
         if(2*(x-n+2)%(x+1)==0&&(x-n+2)!=0){
            a[1]=x;
            a[2*n]=2*(x-n+2)/(x+1);
            break;
         }
        }
        for(int i=1;i<=2*n;i++)cout<<a[i]<<" ";
    
        cout<<endl;    
    }

}