//2025/2/23
#include <iostream>
using namespace std;

struct node{
  char value;
  node *l, *r;
};

void preorder(node* root) {
  if(root != nullptr) {
    cout << root->value;
    preorder(root->l);
    preorder(root->r);
  }
}
void inorder(node* root) {
  if(root != nullptr) {
    inorder(root->l);
    cout << root->value;
    inorder(root->r);
  }
}

void postorder(node* root) {
  if(root != nullptr) {
    postorder(root->l);
    postorder(root->r);
    cout << root->value;
  }
}

int main() {
  char ch = 'A';
  node* p;
  p = new node(ch, nullptr, nullptr);
  ch++;
  p->l = new node(ch, nullptr, nullptr);
  ch++;
  p->r = new node(ch, nullptr, nullptr);
  ch++;
  p->l->l = new node(ch, nullptr, nullptr);
  ch++;
  p->l->r = new node(ch, nullptr, nullptr);
  ch++;
  p->r->l = new node(ch, nullptr, nullptr);
  ch++;
  p->r->r = new node(ch, nullptr, nullptr);
  ch++;
  p->l->l->l = new node(ch, nullptr, nullptr);
  ch++;
  p->l->l->r = new node(ch, nullptr, nullptr);
  ch++;
  p->l->r->l = new node(ch, nullptr, nullptr);
  ch++;
  p->l->r->r = new node(ch, nullptr, nullptr);
  ch++;
  p->r->l->l = new node(ch, nullptr, nullptr);
  ch++;
  p->r->l->r = new node(ch, nullptr, nullptr);
  ch++;
  p->r->r->l = new node(ch, nullptr, nullptr);
  ch++;
  p->r->r->r = new node(ch, nullptr, nullptr);
  cout << "preorder: ";
  preorder(p);
  cout << endl << "inorder: ";
  inorder(p);
  cout << endl << "postorder: ";
  postorder(p);
  cout << endl;
  return 0;
}