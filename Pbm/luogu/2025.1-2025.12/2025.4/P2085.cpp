//2025/4/1
#include <bits/stdc++.h>
using namespace std;

int func(int A, int B, int C, int x) { return A*x*x + B*x + C; }

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  priority_queue<int> q;
  while(n--) {
    int A, B, C; cin >> A >> B >> C;
    int minx = -B / (A*2);
    int l = 1, r = 1, lx = 1, rx = 1;
    if(minx <= 0) l = 0;
    else lx = rx = minx;
    while(1) {
      if(!l && !r) break;
      if(l && lx) {
        int y = func(A,B,C,lx);
        if(q.size() > m) {
          if(y < q.top()) {
            q.push(y); q.pop();
          } else l = 0;
        } else q.push(y);
      } else l = 0;
      if(r) {
        int y = func(A,B,C,rx);
        if(q.size() > m) {
          if(y < q.top()) {
            q.push(y); q.pop();
          } else r = 0;
        } else q.push(y);
      } 
      --lx; ++rx;
    }
  }
  priority_queue<int, vector<int>, greater<int>> rq;
  while(q.size()) {
    rq.push(q.top()); q.pop();
  }
  while(m--) {
    cout << rq.top() << ' '; rq.pop();
  }
  cout << endl;
  return 0;
}