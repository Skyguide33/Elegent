//2026/5/1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll a[1005];

bool is_prime(int num) {
  for(int i = 2; i*i <= num; ++i) {
    if(num%i == 0) return 0;
  }
  return 1;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  ll sum = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  if(n >= 2 && (sum-n)%2) {
    --n; sum -= 2;
  }
  if(n == 1) {
    if(sum != 1 && is_prime(sum)) cout << "Yes" << endl;
    else cout << "No" << endl;
  } else {
    if(sum/n >= 2) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}