// 2025/11/19
#include<bits/stdc++.h>
using namespace std;

struct Node {
  int a, b, c;
  bool operator < (const Node&B) const { 
    if(a != B.a) return a < B.a;
    else if(b != B.b) return b < B.b;
    return c < B.c;
  }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int a[10];
    for(int i = 1; i <= 9; ++i) a[i] = i;
    int cnt = 0;
    int b[4];
    set<Node> st;
    do {
        b[1] = a[1]*100+a[2]*10+a[3];
        b[2] = a[4]*100+a[5]*10+a[6];
        b[3] = a[7]*100+a[8]*10+a[9];
        sort(b+1, b+4);
        // cout << b[1] << ' ' << b[2] << ' ' << b[3] << endl;
        if(b[1]*2 == b[2] && b[1]*3 == b[3]) {
          st.insert({b[1], b[2], b[3]});
        }
    } while(next_permutation(a+1, a+10));
    for(auto&[a, b, c]: st) cout << a << ' ' << b << ' ' << c << endl;
}
