//2026/3/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
 
int vis[1000005], prime[1000005], cnt;
 
void eular_sieve() {
  for(int i = 2; i <= 999999; ++i) {
    if(!vis[i]) {
      prime[++cnt] = i;
      vis[i] = 1;
    }
    for(int j = 1; j <= cnt; ++j) {
      if(i*prime[j] >= 1000000) break;
      vis[i*prime[j]] = prime[j];
      if(i%prime[j] == 0) break;
    }
  }
}
 
pair<int, int> get_c(int ab) {
  int l = 1, r = 999999;
  while(l < r) {
    int mid = (l+r+1)>>1;
    if((mid*154+306)/307 <= ab) l = mid;
    else r = mid-1;
  }
  int lres = l;
  l = 1, r = 999999;
  while(l < r) {
    int mid = (l+r)>>1;
    if(mid*153/307 >= ab) r = mid;
    else l = mid+1;
  }
  int rres = l;
  return {lres, rres};
}
 
pair<int, int> get_ab(int c) {
  int lres = 153*c/307, rres = (154*c+306)/307;
  return {lres, rres};
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  eular_sieve();
  char s; cin >> s;
  int n; cin >> n;
  int l, r;
  if(s == 'c') tie(l, r) = get_ab(n);
  else tie(l, r) = get_c(n);
  // cout << "[l, r]" << l << ' ' << r << endl;
  int num = 1;
  bool flag = 1;
  for(int i = 1; prime[i]*prime[i] <= r; ++i) {
    int pw = 1;
    while(1) {
      if(s == 'c') cout << "? a " << pw*prime[i] << endl;
      else cout << "? c " << pw*prime[i] << endl;
      cout << flush;
      bool res; cin >> res;
      if(res) pw *= prime[i];
      else break;
    }
    num *= pw;
    l = (l+pw-1)/pw; r /= pw;
    if(l == r) {
      num *= l;
      flag = 0;
      break;
    }
  }
  if(flag) {
    int lpos = lower_bound(prime+1, prime+cnt+1, l)-prime;
    int rpos = upper_bound(prime+1, prime+cnt+1, r)-prime-1;
    for(int i = lpos; i <= rpos; ++i) {
      if(s == 'c') cout << "? a " << prime[i] << endl;
      else cout << "? c " << prime[i] << endl;
      cout << flush;
      bool res; cin >> res;
      if(res) {
        num *= prime[i];
        break;
      }
    }
  }
  if(s == 'c') {
    cout << "! " << num << ' ' << n-num << ' ' << n << endl;
  } else {
    if(s == 'a') cout << "! " << n << ' ' << num-n << ' ' << num << endl;
    else cout << "! " << num-n << ' ' << n << ' ' << num << endl;
  }
  return 0;
}