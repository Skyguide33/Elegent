//2025/9/30
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e5+5;
int cnt = 0, root = 0;
struct Node {
  int ls, rs, pri, key, size, lazy;
} t[N];

void newNode(int x) {
  t[++cnt] = {0, 0, rand(), x, 1, 0};
}

void Update(int u) {
  t[u].size = t[t[u].ls].size+t[t[u].rs].size+1;
}

void push_down(int u) {
  if(t[u].lazy) {
    swap(t[u].ls, t[u].rs);
    t[t[u].ls].lazy ^= 1; t[t[u].rs].lazy ^= 1;
    t[u].lazy = 0;
  }
}

void Split(int u, int x, int &L, int &R) {
  if(u == 0) { L = R = 0; return; }
  push_down(u);
  if(t[t[u].ls].size+1 <= x) {
    L = u; Split(t[u].rs, x-t[t[u].ls].size-1, t[u].rs, R);
  } else { R = u; Split(t[u].ls, x, L, t[u].ls); }
  Update(u);
}

int Merge(int L, int R) {
  if(L == 0 || R == 0) return L+R;
  if(t[L].pri > t[R].pri) {
    push_down(L); 
    t[L].rs = Merge(t[L].rs, R);
    Update(L);
    return L;
  } else {
    push_down(R);
    t[R].ls = Merge(L, t[R].ls);
    Update(R);
    return R;
  }
}

void inorder(int u) {
  if(u == 0) return;
  push_down(u);
  inorder(t[u].ls);
  cout << t[u].key << ' ';
  inorder(t[u].rs);
}

int main() {
  srand(time(0));
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; ++i) { newNode(i); root = Merge(root, cnt); }
  while(m--) {
    int l, r; cin >> l >> r;
    int L, R, p;
    Split(root, r, L, R);
    Split(L, l-1, L, p);
    t[p].lazy ^= 1;
    root = Merge(Merge(L, p), R);
  }
  inorder(root);
  return 0;
}