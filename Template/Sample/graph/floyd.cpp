#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int N = 2e3 + 5;

int d[N][N], p[N][N];
int n;
void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = k;
                }
}
void path(int i, int j)
{
    if (p[i][j] == 0)
        return;
    int k = p[i][j];
    path(i, k);
    cout << k << ' ';
    path(k, j);
}

signed main()
{
    cin >> n;
    int m;
    cin >> m;

    floyd();
    int a, b;
    cin >> a >> b;
    cout << a << ' ';
    path(a, b);
    cout << b << '\n';
    return 0;
}