//2025/3/19
#include <bits/stdc++.h>
using namespace std;
const int N = 70;
int maxn = 0, minn = N, Hash[N];
void dfs(int k, int len, int L, int p) {
    if(k == 0) {
        cout << L << endl; exit(0);
    }
    if(len == L) {
        dfs(k-1, 0, L, maxn);
        return;
    }
    for(int i = p; i >= minn; i--) {
        if(Hash[i] && i + len <= L) {
            Hash[i]--;
            dfs(k, len+i, L, i);
            Hash[i]++;
            if(len == 0) break;
            if(len + i == L) break;
        }
    }
    return;
}
int main() {
    int n; cin >> n;
    int sum = 0;
    while(n--) {
    int a; cin >> a;
        Hash[a]++;
        sum += a;
        maxn = max(maxn, a);
        minn = min(minn, a);
    }
    for(int L = maxn; L <= sum/2; L++) {
        if(sum % L == 0) {
            dfs(sum / L, 0, L, maxn);
        }
    }
    cout << sum << endl;
    return 0;
}