//2025/2/24
#include <iostream>
using namespace std;

#if 0
struct node{
  string s;
  node *l, *r;
};

void BuildNode(node* p) {
  if(p->s.length() >= 2) {
    p->l = new node(p->s.substr(0, p->s.length()/2), nullptr, nullptr);
    p->r = new node(p->s.substr(p->s.length()/2), nullptr, nullptr);
    BuildNode(p->l);
    BuildNode(p->r);
  } else return;
}

char GetFBI(const string& s) {
  int sort = s.at(0) - '0';
  for(unsigned i = 1; i < s.length(); i++) {
    if((s.at(i) == '0' && sort == 1) || (s.at(i) == '1' && sort == 0)) {
      sort = 2;
      break;
    } 
  }
  if(sort == 0) return 'B';
  if(sort == 1) return 'I';
  return 'F';
}

void postorder(node* p) {
  if(p == nullptr) return;
  else {
    postorder(p->l);
    postorder(p->r);
    cout << GetFBI(p->s);
    delete p;
  }
}

int main() {
  int N;
  node* p;
  p = new node;
  cin >> N >> p->s;
  BuildNode(p);
  postorder(p);
  cout << endl;
  return 0;
}
#endif
#if 1

char GetFBI(string s) {
  int sort = s.at(0) - '0';
  for(unsigned i = 1; i < s.length(); i++) {
    if((s.at(i) == '0' && sort == 1) || (s.at(i) == '1' && sort == 0)) {
      sort = 2;
      break;
    } 
  }
  if(sort == 0) return 'B';
  else if(sort == 1) return 'I';
  return 'F';
}

void MakeTree(int N, string input) {
  if(N) {
    MakeTree(N-1, input.substr(0, input.length()/2));
    MakeTree(N-1, input.substr(input.length()/2));
  }
  cout << GetFBI(input);
  return;
}
int main() {
  int N;
  string input;
  cin >> N >> input;
  MakeTree(N, input);
  return 0;
}
#endif