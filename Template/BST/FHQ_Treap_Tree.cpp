//2025/9/29
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int N = 1e6+5;
int cnt = 0, root = 0;
struct Node {
  int ls, rs, key, pri, size;
} t[N];

void newNode(int x) {
  t[++cnt] = {0, 0, x, rand(), 1};
}

void Update(int u) {
  t[u].size = t[t[u].ls].size+t[t[u].rs].size+1;
}

void Split(int u, int x, int &L, int &R) {
  if(u == 0) {L = R = 0; return; }
  if(t[u].key <= x) {
    L = u; Split(t[u].rs, x, t[u].rs, R);
  } else {
    R = u; Split(t[u].ls, x, L, t[u].ls);
  }
  Update(u);
}

int Merge(int L, int R) {
  if(L == 0 || R == 0) return L+R;
  if(t[L].pri > t[R].pri) {
    t[L].rs = Merge(t[L].rs, R);
    Update(L);
    return L;
  } else {
    t[R].ls = Merge(L, t[R].ls);
    Update(R);
    return R;
  }
}

void Insert(int x) {
  int L, R;
  Split(root, x, L, R);
  newNode(x);
  int aa = Merge(L, cnt);
  root = Merge(aa, R);
}

void Del(int x) {
  int L, R, p;
  Split(root, x, L, R);
  Split(L, x-1, L, p);
  p = Merge(t[p].ls, t[p].rs);
  root = Merge(Merge(L, p), R);
}

int Rank(int x) {
  int L, R;
  Split(root, x-1, L, R);
  int tmp = t[L].size+1;
  root = Merge(L, R);
  return tmp;
}

int kth(int u, int k) {
  if(k == t[t[u].ls].size+1) return t[u].key;
  else if(k <= t[t[u].ls].size) return kth(t[u].ls, k);
  else return kth(t[u].rs, k-t[t[u].ls].size-1);
}

int Precursor(int x) {
  int L, R;
  Split(root, x-1, L, R);
  int tmp = kth(L, t[L].size);
  root = Merge(L, R);
  return tmp;
}

int Successor(int x) {
  int L, R;
  Split(root, x, L, R);
  int tmp = kth(R, 1);
  root = Merge(L, R);
  return tmp;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  srand(time(0));
  int n; cin >> n;
  while(n--) {
    int opt, x; cin >> opt >> x;
    switch(opt) {
      case 1: Insert(x); break;
      case 2: Del(x); break;
      case 3: cout << Rank(x) << endl; break;
      case 4: cout << kth(root, x) << endl; break;
      case 5: cout << Precursor(x) << endl; break;
      case 6: cout << Successor(x) << endl; break;
    }
  }
  return 0;
}