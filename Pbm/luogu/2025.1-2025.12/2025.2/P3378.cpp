//2025/2/25
#include <iostream>
using namespace std;

int nodes[1000005], len = 0;

void push(int x) {
  nodes[++len] = x;
  int i = len;
  while(i > 1 && nodes[i] < nodes[i/2]) {
    int t = nodes[i];
    nodes[i] = nodes[i/2];
    nodes[i/2] = t;
    i /= 2;
  }
}
void pop() {
  nodes[1] = nodes[len--];
  int i = 1;
  while(2*i <= len) {
    int son = 2*i;
    if(son < len && nodes[son+1] < nodes[son]) son++;
    if(nodes[son] < nodes[i]) {
      int t = nodes[son];
      nodes[son] = nodes[i];
      nodes[i] = t;
      i = son;
    } else break;
  }
}
int main() {
  int n, op, x;
  cin >> n; 
  while(n--) {
    cin >> op;
    if(op == 1) { cin >> x; push(x); }
    else if(op == 2) { cout << nodes[1] << endl;}
    else pop(); 
  }
  return 0;
}