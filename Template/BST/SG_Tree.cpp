//2025/9/24 rewrite
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N= 1e6+5;
const double alpha = 0.72;

// val:节点的值 tot:以该节点为根的子树的总节点个数(包括被删除的节点) 
// size:以该节点为根的子树的有效节点个数 del:当前节点 1未删除/0已删除
struct Node { 
  int ls, rs, val, tot, size, del;
} t[N]; // 内存池
int order[N], cnt; // 暂时存储被拍平的节点
int tree_stack[N], top = 0; // 存储未被使用的内存池下标
int root = 0; // 树的根节点

// 中序遍历, 保存有效节点的遍历序列，回收已被删除的节点
void inorder(int u) {
  if(!u) return;
  inorder(t[u].ls);
  if(t[u].del) order[++cnt] = u;
  else tree_stack[++top] = u;
  inorder(t[u].rs);
}

// 初始化节点
void Initnode(int u) {
  t[u] = {0, 0, 0, 1, 1, 1};
}

// 根据左右子树更新当前节点的信息(仅被build函数调用)
void Update(int u) {
  t[u].size = t[t[u].ls].size+t[t[u].rs].size+1;
  t[u].tot = t[t[u].ls].tot+t[t[u].rs].tot+1;
}

// 通过order数组建树(仅被rebuild函数调用)
void build(int l, int r, int &u) {
  int mid = (l+r)>>1;
  u = order[mid];
  if(l == r) return Initnode(u);
  if(l < mid) build(l, mid-1, t[u].ls);
  else if(l == mid) t[u].ls = 0;
  build(mid+1, r, t[u].rs);
  Update(u);
}

// 拍平重建以u为根的子树
void rebuild(int &u) {
  cnt = 0;
  inorder(u);
  if(cnt) build(1, cnt, u);
  else u = 0;
}

// 判断以u为根的子树是否不平衡
bool notbalance(int u) {
  if((double)t[u].size*alpha <= (double)max(t[t[u].ls].size, t[t[u].rs].size)) 
    return 1;
  return 0;
}

// 插入新节点
void Insert(int &u, int x) {
  if(!u) {
    u = tree_stack[top--]; // 向内存池申请内存
    t[u].val = x;
    Initnode(u);
    return;
  }
  ++t[u].size;
  ++t[u].tot;
  if(t[u].val >= x) Insert(t[u].ls, x);
  else Insert(t[u].rs, x);
  if(notbalance(u)) rebuild(u); // 如果树不平衡, 拍平重建
}

// 查询值x的排名(比x小的数的个数)
int Rank(int u, int x) {
  if(u == 0) return 0;
  if(x > t[u].val) return t[t[u].ls].size+t[u].del+Rank(t[u].rs, x);
  return Rank(t[u].ls, x);
}

// 查询排名为k的节点(排名从1开始)的值
int kth(int k) {
  int u = root;
  while(u) {
    if(t[u].del && t[t[u].ls].size+1 == k) return t[u].val; // 当前节点排名为k
    else if(t[t[u].ls].size >= k) u = t[u].ls; // 排名为k的节点在左儿子
    else {
      k -= t[t[u].ls].size+t[u].del; 
      u = t[u].rs; // 排名为k的节点在右儿子
    }
  }
  return t[u].val;
}

// 删除排名为k的节点(排名从1开始)
void Del_k(int &u, int k) {
  --t[u].size;
  if(t[u].del && t[t[u].ls].size+1 == k) { t[u].del = 0; return; }
  if(t[t[u].ls].size+t[u].del >= k) Del_k(t[u].ls, k);
  else Del_k(t[u].rs, k-t[t[u].ls].size-t[u].del);
}

// 删除第一个值>=x的节点
void Del(int x) {
  Del_k(root, Rank(root, x)+1);
  if(t[root].tot*alpha >= t[root].size) rebuild(root);
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  for(int i = N-1; i >= 1; --i) tree_stack[++top] = i;
  int q; cin >> q;
  while(q--) {
    int opt, x; cin >> opt >> x;
    switch(opt) {
      case 1: Insert(root, x); break;
      case 2: Del(x); break;
      case 3: cout << Rank(root, x)+1 << endl; break;
      case 4: cout << kth(x) << endl; break;
      case 5: cout << kth(Rank(root, x)) << endl; break;
      case 6: cout << kth(Rank(root, x+1)+1) << endl; break;
    }
  }
  return 0;
}