#include <iostream>
using namespace std;

int e[100005], v[100005];

int main() {
    int n, m, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> e[i];
    cin >> m;
    for(int i = 0; i < m; i++) cin >> v[i];
    for(int i = 0; i < m; i++) {
        if(v[i] >= e[ans]) ans++;
        if(ans == n) break;
    }
    cout << ans << endl;
    return 0;
}