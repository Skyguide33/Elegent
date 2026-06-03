//2025/2/28
#include <iostream>
using namespace std;

int q[10005], len;

void push(int x) {
  q[++len] = x;
  int i = len;
  while(q[i] < q[i/2] && i >= 2) {
    int t = q[i];
    q[i] = q[i/2];
    q[i/2] = t;
    i /= 2;
  }
}

void pop() {
  q[1] = q[len--];
  int i = 1;
  while(i*2 <= len) {
    int son = i*2;
    if(son < len && q[son] > q[son+1]) son++;
    if(q[i] > q[son]) {
      int t = q[son];
      q[son] = q[i];
      q[i] = t;
      i = son;
    } else break;
  }
}

int top() { return q[1]; }
int main() {
  int n, t1, t2, ans = 0;
  cin >> n;
  while(n--) {
    cin >> t1;
    push(t1);
  }
  while(len != 1) {
    t1 = top(); pop();
    t2 = top(); pop();
    ans += t1+t2;
    push(t1+t2);
  }
  cout << ans << endl;
  return 0;
}