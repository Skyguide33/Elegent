//2025/2/28
#if 0
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, x;
  vector<int>q;
  cin >> N;
  cin >> x;
  q.push_back(x);
  cout << x << endl;
  for(int i = 1; i < N; i++) {
    cin >> x;
    if(q[0] >= x) q.insert(q.begin(), x);
    else if(q[q.size()-1] <= x) q.push_back(x);
    else {
      int l = 0, r = q.size();
      while(l < r) {
        int mid = l + (r-l)/2;
        if(q[mid] >= x) r = mid;
        else l = mid+1;
      }
      q.insert(q.begin()+l, x);
    }
    if(i%2 == 0) cout << q[i/2] << endl;
  }
  return 0;
}
#endif
#if 1
#include <iostream>
#include <queue>
using namespace std;

int main() {
  int N, x;
  cin >> N;
  priority_queue<int, vector<int>, greater<int>>q1;
  priority_queue<int>q2;
  cin >> x;
  q1.push(x);
  q2.push(x);
  N--;
  cout << x << endl;
  while(N--) {
    cin >> x;
    if(q1.top() < x) q1.push(x);
    else if(q2.top() > x)q2.push(x);
    if(N%2 == 1) {
      if(q1.size() > q2.size()) {
        q1.pop();
        q2.push(q1.top());
      } else if(q1.size() < q2.size()){
        q2.pop();
        q1.push(q2.top());
      }
      cout << q1.top() << endl;
    }
  }
}
#endif