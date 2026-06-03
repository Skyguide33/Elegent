#include<bits/stdc++.h>
using namespace std;

int ans[1000005];
int main(){
  int n; cin >> n;
  string c; cin >> c;
  c = ' '+c;
	int id = 1, l=0,r=n+1;
	for(int i=2;i<=n;i++){
		if(c[i]>c[i-1]){
			for(int j=i-1;j>=id;j--) ans[--r]=j;
			id=i;
		}
		if(c[i]<c[i-1]){
			for(int j=id;j<i;j++) ans[++l]=j;
			id=i;
		}
	}
	for(int i=id;i<=n;i++) ans[++l]=i;
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	return 0;
}
