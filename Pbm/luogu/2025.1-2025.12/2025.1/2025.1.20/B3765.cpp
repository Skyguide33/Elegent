//2025/1/20
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>>a(N+1);
  for(int i = 1; i <= N; i++) {
    int T;
    cin >> T;
    while(T--) {
      int n;
      cin >> n;
      a[i].push_back(n);
    }
  }
  vector<int>ans(1,1);
  ans.insert(ans.end(), a[1].begin(), a[1].end());
  auto ans2 = ans;
  for(unsigned i = 0; i < ans.size(); i++) {
    for(unsigned j = 0; j < a[ans[i]].size(); j++) {
      bool same = 0;
      for(unsigned k = 0; k < ans2.size(); k++) {
        if(ans2[k] == a[ans[i]][j]) {
          same = 1;
          break;
        }
      }
      if(!same) ans2.push_back(a[ans[i]][j]);
    }
  }
  // cout << "content:" << endl;
  // for(auto& x: ans2) cout << x << ' ';
  // cout << endl;
  cout << ans2.size() << endl;
  return 0;
}