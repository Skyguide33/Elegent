//2025/2/25
#include <iostream>
using namespace std;

struct node {
  char ch;
  int l = -1, r = -1;
};

void preorder(node *Nodes, int pos) {
  cout << Nodes[pos].ch;
  if(Nodes[pos].l != -1) preorder(Nodes, Nodes[pos].l);
  if(Nodes[pos].r != -1) preorder(Nodes, Nodes[pos].r);
  return;
}
int main() {
  int n, tail = -1, p;
  cin >> n;
  node Nodes[n];
  for(int i = 1; i <= n; i++) {
    char input[4];
    int ppos = -1, lpos = -1, rpos = -1;
    cin >> input;
    for(int j = 0; j <= tail; j++) {
      if(input[0] == Nodes[j].ch) ppos = j;
      if(input[1] == Nodes[j].ch) lpos = j;
      if(input[2] == Nodes[j].ch) rpos = j;
      
    }
    if(ppos == -1) {
      Nodes[++tail].ch = input[0];
      ppos = tail;
    }
    if(lpos == -1 && input[1] != '*') {
      Nodes[++tail].ch = input[1];
      lpos = tail;
    }
    if(rpos == -1 && input[2] != '*') {
      Nodes[++tail].ch = input[2];
      rpos = tail;
    } 
    Nodes[ppos].l = lpos;
    Nodes[ppos].r = rpos;
    if(i == 1) p = ppos;

  }
  preorder(Nodes, p);
  cout << endl;
  return 0;
}