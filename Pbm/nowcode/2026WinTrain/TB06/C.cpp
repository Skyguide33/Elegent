//2026/2/13
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 1000005
#define ls p<<1
#define rs p<<1|1

int tree[N<<2], tag[N<<2], cost;

void query(int L, int R, int p, int pl, int pr) {
  if(L <= pl && pr <= R) {
    cost += tree[p];
    return;
  }
  if(!tag[p]) ++cost;
  int mid = (pl+pr)>>1;
  if(L <= mid) query(L, R, ls, pl, mid);
  if(R > mid) query(L, R, rs, mid+1, pr);
}

void destroy(int L, int R, int p, int pl, int pr) {
  if(pl == L && pr == R) {
    tag[p] = 1;
    while(p) {
      if(!tag[p]) break;
      tree[p] = tree[ls]+tree[rs];
      p >>= 1;
    }
    return;
  }
  int mid = (pl+pr)>>1;
  if(L <= mid) destroy(L, R, ls, pl, mid);
  else destroy(L, R, rs, mid+1, pr);
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= (n<<2); ++i) tree[i] = 1;
  for(int i = 1; i <= n; ++i) {
    int o, l, r; cin >> o >> l >> r;
    if(o == 1) destroy(l, r, 1, 1, n);
    else {
      cost = 0;
      query(l, r, 1, 1, n);
      cout << cost << endl;
    }
  }
  return 0;
}