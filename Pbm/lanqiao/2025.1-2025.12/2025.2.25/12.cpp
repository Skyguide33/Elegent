#include <iostream>
using namespace std;

int a[105][5005];
int main() {
    int n, m, ans=0, r1=0, r2=0, c1=0, c2=0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            a[i][j] += a[i][j-1];
        }
        for(int j = 1; j <= m; j++) {
            a[i][j] += a[i-1][j];
        }
    }
    for(r1 = 2; r1 < n; r1++) {
        for(r2 = r1; r2 < n; r2++) {
            for(c1 = 2; c1 < m; c1++) {
                for(c2 = c1; c2 < m; c2++) {
                    int count = (a[r2][m]-a[r1-1][m])+(a[n][c2]-a[n][c1-1])-(a[r2][c2]-a[r2][c1-1]+a[r1-1][c1-1]-a[r1-1][c2]);
                    if(count > ans) ans = count;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}