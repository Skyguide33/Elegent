#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
const int N =1e6+10;

int fa[N];
int fa1[N];
int find(int x) {
	if (fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}

void hb(int a, int b) {
	if (find(a) != find(b)) {
		fa[find(a)] = find(b);
	}
}
int find1(int x) {
	if (fa1[x] == x)return x;
	return fa1[x] = find1(fa1[x]);
}

void hb1(int a, int b) {
	if (find1(a) != find1(b)) {
		fa1[find1(a)] = find1(b);
        find1(a);
	}
}
int main(){
int t;
cin>>t;
while(t--){
    int n,m;
    int ans=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)fa[i]=i,fa1[i]=i;
    vector<vector<int>>s(n+1,vector<int>(m+1));
    vector<int>st(n+1,1);
    vector<pair<int,int>>yz;
    for(int i=1;i<=n;i++){
      string sr;
      cin>>sr;
      for(int j=1;j<=m;j++){
        s[i][j]=sr[j-1]-'0';
      }
    }
    for(int i=1;i<=(m+1)/2;i++) {
        int op=0;
        int a=0,b=0;
        for(int j=1;j<=n;j++){
            if(a==0&&s[j][i])a=j;
            else if(b==0&&s[j][i])b=j;
            op+=s[j][i];
        }
       
          for(int j=1;j<=n;j++) {
            if(a==0&&s[j][m-i+1])a=j;
            else if(b==0&&s[j][m-i+1])b=j;
            op+=s[j][m-i+1];
        }
        if(op>2) {
            ans=0;
            break;
        }
      
        if(a==b)continue;
        if(a==0||b==0)continue;
        st[a]=0;st[b]=0;
        if((s[a][i]&&s[b][i])||(s[a][m-i+1]&&s[b][m-i+1]))yz.push_back({a,b});
        else if(find(a)!=find(b))hb(a,b);
        if(find1(a)!=find1(b))hb1(a,b);
    }

    if(ans){
        for(int i=0;i<yz.size();i++){
            int a=yz[i].first;
            int b=yz[i].second;
            if(find(a)==find(b)){
                ans=0;
                break;
            }
        }
    }
    if(ans){
        for(int i=1;i<=n;i++){
            if(st[i])ans*=2;
            else if(find1(i)==i)ans*=2;
            ans%=mod;
        }
    }
   
    cout<<ans<<endl;
}
}