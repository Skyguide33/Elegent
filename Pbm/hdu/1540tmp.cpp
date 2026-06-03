#include<bits/stdc++.h>
using namespace std;
const int N = 50005;
#define ls p<<1
#define rs p<<1|1
int tree[N<<2], pre[N<<2], suf[N<<2], his[N];             //记录村庄被毁的历史

void push_up(int p, int len){      //len是结点p的长度
  pre[p] = pre[ls];        //父结点接收子结点的前缀信息
  suf[p] = suf[rs];
  if(pre[ls] == (len-(len>>1)))  pre[p] = pre[ls]+pre[rs]; //左儿子都是1
  if(suf[rs] == (len>>1)) suf[p] = suf[ls]+suf[rs]; //右儿子都是1
}

void build(int p, int pl, int pr){
  if(pl == pr) {tree[p] = pre[p] =  suf[p]  = 1;  return;}
  int mid = (pl+pr) >> 1;
  build(ls, pl, mid);   
  build(rs, mid+1, pr);
  push_up(p, pr-pl+1);
}

void update(int x, int c, int p, int pl, int pr){
  if(pl == pr) { tree[p] = suf[p] = pre[p] = c; return; }   //更新叶子结点信息
  int mid = (pl+pr)>>1;
  if(x <= mid) update(x, c, ls, pl, mid);
  else update(x, c, rs, mid+1, pr);
  push_up(p, pr-pl+1);
}

int query(int x, int p, int pl, int pr){
  if(pl == pr) return tree[p];  //返回叶子的值
  int mid = (pl+pr)>>1;
  if(x <= mid){           //左子树
    if(x+suf[ls] > mid) return suf[ls]+pre[rs];
    else return query(x,ls,pl,mid);
  }
  else{               //右子树
    if(mid+pre[rs] >= x) return pre[rs]+suf[ls];
    else return query(x, rs, mid+1, pr);
  }
}

int main(){
  int n, m, x, tot;   
  while(cin >> n >> m)  {
    build(1, 1, n);
    tot = 0;
    while(m--){
      char op; cin >> op;
      if(op == 'Q'){
        cin >> x;  
        cout << query(x,1,1,n) << endl;
      }
      else if(op == 'D'){
        cin >> x;  
        his[++tot] = x;      //记录毁灭的历史
        update(x,0,1,1,n);
      }
      else update(his[tot--],1,1,1,n);   //重建
    }
  }
}