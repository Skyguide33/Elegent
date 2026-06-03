#include<bits/stdc++.h>
using namespace std;
int n,x,a[100005],ls[100005],rs[100005],vis[100005],flag;
void dfs(int x){
	cout<<x<<' ';
	if(ls[x]) dfs(ls[x]);
	if(rs[x]) dfs(rs[x]);
}
stack<int> s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n;
	for(int i=1;i<=n;i++){ 
		cin>>x;
		a[x]=i;
	}
	for(int i=1;i<=n;i++){
		flag=0;
		while(s.size() && a[s.top()]>a[i]) flag=s.top(),s.pop();
		if(s.size()) rs[s.top()]=i;

				if(flag) ls[i]=flag;
		s.push(i);
	} 
	for(int i=1;i<=n;i++){
		vis[ls[i]]=1;
		vis[rs[i]]=1;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
			break;
		}
	}
	return 0;
}