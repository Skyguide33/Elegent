//2026/5/14
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int pcnt[1024];
vector<pair<int, int>> psum[1024];

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m, A, B; cin >> n >> m >> A >> B;
  for(int i = 0; i < (1<<m); ++i) {
    int tt = i;
    for(int j = m; j >= 1; --j) {
      if(tt&1) pcnt[i] += j;
      tt >>= 1;
    }
  }
  for(int i = 1; i <= n; ++i) {
    int s = 0;
    for(int j = 1; j <= m; ++j) {
      char ch; cin >> ch;
      s = (s<<1)|(ch-'0');
    }
    if(psum[s].empty()) psum[s].push_back({0, 0});
    psum[s].push_back({i, psum[s].back().second+i});
    // cout << "push " << s << ' ' << i << ' ' << psum[s].back().second+i << endl;
  }
  int ans = -1e18;
  for(int i = 0; i < (1<<m); ++i) {
    int res = 0;
    for(int j = 0; j < (1<<m); ++j) {
      if(psum[j].empty()) continue;
      int s = i^j;
      if(A >= 0) {
        int l = 1, r = n+1;
        while(l < r) {
          int mid = (l+r)>>1;
          if(A*mid*(m-2*popcount((unsigned)s))+B*(m*(m+1)/2-2*pcnt[s]) >= 0) r = mid;
          else l = mid+1;
        }
        int k = l;
        int cnt = upper_bound(psum[j].begin(), psum[j].end(), make_pair(k, 0))-psum[j].begin()-1;
        //  cout << "cnt1=" << cnt << endl;
        res += A*psum[j][cnt].second*popcount((unsigned)s)+B*cnt*pcnt[s];
        res += A*(psum[j].back().second-psum[j][cnt].second)*(m-popcount((unsigned)s))+B*(psum[j].size()-1-cnt)*(m*(m+1)/2-pcnt[s]);
      } else {
        int l = 0, r = n;
        while(l < r) {
          int mid = (l+r+1)>>1;
          if(A*mid*(m-2*popcount((unsigned)s))+B*(m*(m+1)/2-2*pcnt[s]) >= 0) l = mid;
          else r = mid-1;
        }
        int k = l;
        int cnt = upper_bound(psum[j].begin(), psum[j].end(), make_pair(k, 1e18))-psum[j].begin()-1;
        // cout << "cnt2=" << cnt << endl;
        res += A*(psum[j].back().second-psum[j][cnt].second)*popcount((unsigned)s)+B*(psum[j].size()-1-cnt)*pcnt[s];
        res += A*psum[j][cnt].second*(m-popcount((unsigned)s))+B*cnt*(m*(m+1)/2-pcnt[s]);
      }
    }
    // cout << "res=" << res << endl;
    ans = max(ans, res);
  }
  cout << ans << endl;
  return 0;
}