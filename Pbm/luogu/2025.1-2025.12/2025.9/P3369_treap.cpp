//2025/9/29
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e6+5;

int cnt = 0;
struct Node { int ls, rs, key, pri, size; } t[N];

inline void newNode(int x) {
  t[++cnt] = {0, 0, x, rand(), 1};
}

inline void Update(int u) {
  t[u].size = t[t[u].ls].size+t[t[u].rs].size+1;
}

inline void rotate(int &o, int d) {
  int k;
  if(d == 1) {
    k = t[o].rs;
    t[o].rs = t[k].ls;
    t[k].ls = o;
  } else {
    k = t[o].ls;
    t[o].ls = t[k].rs;
    t[k].rs = o;
  }
  t[k].size = t[o].size;
  Update(o);
  o = k;
}

void Insert(int &u, int x) {
  if(u == 0) { newNode(x); u = cnt; return; }
  ++t[u].size;
  if(x >= t[u].key) Insert(t[u].rs, x);
  else Insert(t[u].ls, x);
  if(t[u].ls != 0 && t[u].pri > t[t[u].ls].pri) rotate(u, 0);
  if(t[u].rs != 0 && t[u].pri > t[t[u].rs].pri) rotate(u, 1);
  Update(u);
}

void Del(int &u, int x) {
  --t[u].size;
  if(t[u].key == x) {
    if(t[u].ls == 0 && t[u].rs == 0) { u = 0; return; }
    if(t[u].ls == 0 || t[u].rs == 0) { u = t[u].ls+t[u].rs; return; }
    if(t[t[u].ls].pri < t[t[u].rs].pri) { rotate(u, 0); Del(t[u].rs, x); return; }
    else { rotate(u, 1); Del(t[u].ls, x); return; }
  }
  if(t[u].key >= x) Del(t[u].ls, x);
  else Del(t[u].rs, x);
  Update(u);
}

int Rank(int u, int x) {
  if(u == 0) return 0;
  if(x > t[u].key) return t[t[u].ls].size+1+Rank(t[u].rs, x);
  return Rank(t[u].ls, x);
}

int kth(int u, int k) {
  if(k == t[t[u].ls].size+1) return t[u].key;
  else if(k > t[t[u].ls].size+1) return kth(t[u].rs, k-t[t[u].ls].size-1);
  else return kth(t[u].ls, k);
}

int Precursor(int u, int x) {
  if(u == 0) return 0;
  if(t[u].key >= x) return Precursor(t[u].ls, x);
  int tmp = Precursor(t[u].rs, x);
  if(tmp == 0) return t[u].key;
  return tmp;
}

int Successor(int u, int x) {
  if(u == 0) return 0;
  if(t[u].key <= x) return Successor(t[u].rs, x);
  int tmp = Successor(t[u].ls, x);
  if(tmp == 0) return t[u].key;
  return tmp;
}



int main() {
  cin.tie(0) -> sync_with_stdio(0);
  srand(time(0));
  int root = 0;
  int n; cin >> n;
  while(n--) {
    int opt, x; cin >> opt >> x;
    switch(opt) {
      case 1: Insert(root, x); break;
      case 2: Del(root, x); break;
      case 3: cout << Rank(root, x)+1 << endl; break;
      case 4: cout << kth(root, x) << endl; break;
      case 5: cout << Precursor(root, x) << endl; break;
      case 6: cout << Successor(root, x) << endl; break;
    }
  }
  return 0;
}