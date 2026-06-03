//2025/4/14
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, ans = 0; cin >> N;
    for(int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        if(x > 1) ans++;
    }
    cout << ans << endl;
    return 0;
}