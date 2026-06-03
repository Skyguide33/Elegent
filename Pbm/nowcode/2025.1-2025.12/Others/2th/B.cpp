// //2025/7/17
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// ll a[500005];\

// bool cmp(int a, int b) { return a > b; }

// bool judge(int n) {
//   for(int i = 1; i < n; ++i) {
//     int p = max(a[i], a[i+1]), q = max()
//   }
//   return 1;
// }

// void solve() {
//   int n; cin >> n;
//   for(int i = 1; i <= n; ++i)  cin >> a[i];
//   sort(a+1, a+n+1, cmp);
//   bool yes = judge(n);
//   if(yes) cout << "YES" << endl;
//   else cout << "NO" << endl;
// }
 
// int main() {
//   cin.tie(0) -> sync_with_stdio(0);
//   int T; cin >> T;
//   while(T--) solve();
//   return 0;
// }
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define PII pair<ll, ll>
#define endl '\n'
#define int ll
// #define lll __int128
#define yes cout << "Yes\n"
#define no cout << "No\n"

const int N = 1e6 + 5;
const int P = 998244353;
// const int P = 1e9 + 7;

void solve()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int t = 0;
  for (int i = 62; i >= 0 && t <= n; i--)
  {
    int x = a.end() - lower_bound(a.begin(), a.end(), (1 << i));
    if (x - t > 1)
    {
      cout << "NO\n";
      return;
    }
    t = x;
  }
  cout << "YES\n";
}

signed main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int TT = 1;
  cin >> TT;
  while (TT--)
    solve();
  return 0;
}
