//2025/2/18
#include <iostream>
#include <vector>
using namespace std;

int a[100005];
int main() {
  int m, n, T, t;
  char opt[5];
  bool find;
  vector<int>q;
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> a[i];
  cin >> T;
  for(int i = 0; i < T; i++) {
    cin >> opt;
    if(opt[1] == 'u') {
      cin >> t;
      find = 0;
      //cout << "case1" << endl;
      for(int j = q.size()-1; j >= 0; j--) {
        if(a[q[j]] == a[t]) {
          q.insert(q.begin()+j+1, t);
          find = 1;
          break;
        }
      }
      if(!find) q.push_back(t);
    } else {
      cout << q.front() << endl;
      q.erase(q.begin());
    }
  }
}