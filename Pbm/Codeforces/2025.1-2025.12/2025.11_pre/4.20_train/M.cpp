#include<iostream>
using namespace std;
const int N=3e5+10;
long long a[N],b[N];
int n;
bool check(long long x){
  long long l=-1e9,r=1e9;
  for(int i=1;i<=n;i++){
    long long ll=a[i]-x*b[i];
    long long rr=x*b[i]+a[i];
    if(rr<l||ll>r)return false;
    if(ll>l)l=ll;
    if(rr<r)r=rr;
  }
  return true;
}
int main(){
  int t;
  cin>>t;
  while(t--){
  
cin>>n;
for(int i=1;i<=n;i++){
  cin>>a[i];
}
for(int i=1;i<=n;i++){
  cin>>b[i];
}
int l=0,r=1e9,mid;
while(l<r){
  mid=(l+r)/2;
  if(check(mid)){
   r=mid;
  }
  else{
    l=mid+1;
  }
}
cout<<l<<endl;

  }
}