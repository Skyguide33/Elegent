#include<bits/stdc++.h>
using namespace std;
string s[1000000];
int dp[1000000];
int check(int x,int y){
	if(x==-1||y==-1)return -1;
	if(x==-2||y==-2)return -2;
	return max(x,y);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int T,n,m,k,i,j;
	for(cin>>T;T>0;T--)
	{
		cin>>n>>m>>k;
		for(i=0;i<n;i++) {
            cin>>s[i]; dp[i]=-2;
        }
		for(j=m-2;j>-1;j--)
		{
			for(i=0;i<n;i++)
			{
				if(s[i][j+1]=='1')dp[i]=0;
				else
				{
					if(dp[i]>=0)dp[i]++;
					if(dp[i]==k)dp[i]=-1;
				}
			}
			for(i=0;i<n-1;i++)
			{
				if(s[i][j]=='1')continue;
				dp[i+1]=check(dp[i+1],dp[i]);
			}
			for(i=n-1;i>0;i--)
			{
				if(s[i][j]=='1')continue;
				dp[i-1]=check(dp[i-1],dp[i]);
			}
		}
		if(dp[0]==-1)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}