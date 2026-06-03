#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <iomanip>
#define LL long long
#define ULL unsigned long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define PDD pair<double,double>
#define x first
#define y second
using namespace std;
const int N=1e5+5,mod=1e9+7;
map<string,int> f;				//用map记录到达每个状态的步数
void bfs()
{
	queue<string> q;
	q.push("0000");				//“0000”为起点
	f["0000"]=0;
	while(q.size())
	{
		auto u=q.front();
		q.pop();
		string a,b;
		for(int i=0;i<4;i++)			//枚举每一个区间[i,j]
			for(int j=i;j<4;j++)
			{
				a=b=u;
				for(int k=i;k<=j;k++)
				{
					a[k]=(u[k]-'0'+1)%10+'0';		//a记录u在[i,j]区间内+1得到的状态
					b[k]=(u[k]-'0'+9)%10+'0';		//b记录u在[i,j]区间内-1得到的状态
				}
				if(f.find(a)==f.end())		//如果f中没有a状态，则将其放入队列
				{
					q.push(a);
					f[a]=f[u]+1;
				}
				if(f.find(b)==f.end())		//同上
				{
					q.push(b);
					f[b]=f[u]+1;
				}
			}
	}
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	bfs();					//bfs预处理出所有答案
  for(auto [xx, yy]: f) {
    cout << xx << ' ' << yy << endl;
  }
	return 0; 
}
