#include<bits/stdc++.h>
using namespace std;
const int  N = 200010;
const double alpha = 0.75; //替罪羊树的不平衡率
#define lc t[u].ls
#define rc t[u].rs
struct Point{
	int dim[2],val;         //dim[0]即x，dim[1]即y
	Point(){};
	Point(int x,int y,int vall){dim[0]=x,dim[1]=y,val=vall;}
};
Point order[N]; int cnt;    //替罪羊树：用于拍平后存数据
struct kd_tree{
	int ls,rs;
	int mi[2],ma[2]; //mi[i]: 第i维上区间的下界; ma[i]:第i维上区间的上界
	int sum;         //以该点为根的子树权值之和
	int size;
	Point p;
}t[N];
int tot,root;
int top,tree_stack[N];    //替罪羊树：回收
int now;
bool cmp(Point a,Point b){return a.dim[now]<b.dim[now];}
void update(int u){
	for(int i=0;i<2;i++){
		t[u].mi[i] = t[u].ma[i] = t[u].p.dim[i];
		if(lc){
			t[u].mi[i] = min(t[u].mi[i],t[lc].mi[i]);
			t[u].ma[i] = max(t[u].ma[i],t[lc].ma[i]);
		}
		if(rc){
			t[u].mi[i] = min(t[u].mi[i],t[rc].mi[i]);
			t[u].ma[i] = max(t[u].ma[i],t[rc].ma[i]);
		}
	}
	t[u].sum = t[lc].sum + t[u].p.val+t[rc].sum;
	t[u].size = t[lc].size + t[rc].size+1;
}
void slap(int u)   {            //替罪羊树：拍平
	if(!u) return;
	slap(lc);                   //这里用中序遍历。其实先序、后序也行
	order[++cnt] = t[u].p;
	tree_stack[++top] = u;      //回收结点
	slap(rc);
}
int build(int l,int r,int d) {   //替罪羊树：建树
if(l>r) return 0;
int u;
if(top)   u = tree_stack[top--];
    else      u = ++tot;
int mid=(l+r)>>1;
    now = d;
nth_element(order+l, order+mid, order+r+1, cmp);
t[u].p = order[mid];
lc = build(l,mid-1,d^1);    //奇偶轮转法。没有用例题hdu2966的一般轮转法
rc = build(mid+1,r,d^1);
update(u);
return u;
}
bool notbalance(int u){          //替罪羊树：判断子树u是否平衡
    if(t[lc].size>alpha*t[u].size || t[rc].size>alpha*t[u].size)
        return true;             //不平衡了
    return false;                //还是平衡的
}
void Insert(int &u,Point now,int d){
	if(!u)	{
		if(top)   u=tree_stack[top--];
		else      u = ++tot;
		lc = rc = 0,t[u].p = now;
		update(u);
		return;
	}
	if(now.dim[d] <= t[u].p.dim[d])  Insert(lc,now,d^1);//按第d维的坐标比较
	else                             Insert(rc,now,d^1);
	update(u);
	if(notbalance(u)){                //不平衡
        cnt = 0;
		slap(u);                     //拍平
		u = build(1,t[u].size,d);    //重建
	}
}
int query(int u,int x1,int y1,int x2,int y2){
	if(!u) return 0;
	int X1=t[u].mi[0], Y1=t[u].mi[1], X2=t[u].ma[0], Y2=t[u].ma[1];
if(x1<=X1 && x2>=X2 && y1<=Y1 && y2>=Y2)   return t[u].sum; 
//子树表示的矩形完全在询问矩形范围内
	if(x1>X2 || x2<X1 || y1>Y2 || y2<Y1)	 return 0;        
//子树表示的矩形完全在询问矩形范围外
	int ans=0;
	X1=t[u].p.dim[0], Y1=t[u].p.dim[1], X2=t[u].p.dim[0], Y2=t[u].p.dim[1];
    if(x1<=X1 && x2>=X2 && y1<=Y1 && y2>=Y2)  ans+=t[u].p.val;//根在询问矩形内
	ans += query(lc,x1,y1,x2,y2) + query(rc,x1,y1,x2,y2);     //递归左右子树
	return ans;
}
int main(){
	int n; cin >> n;
	int ans=0;
	while(1){
        int opt;scanf("%d",&opt);
		if(opt==1){
			int x,y,val; scanf("%d%d%d",&x,&y,&val);
			x^=ans,y^=ans,val^=ans;
			Insert(root,Point(x,y,val),0);
		}
		if(opt==2){
			int x1,y1,x2,y2; scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			x1^=ans,y1^=ans,x2^=ans,y2^=ans;
            ans = query(root,x1,y1,x2,y2);
			printf("%d\n",ans);
		}
		if(opt==3) break;
	}
}
