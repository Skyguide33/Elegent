#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int N = 2e5 + 5;

int a[N], b[N], c[N];
int f[N];
signed main()
{
    int num = 1;
    int n, m, v, w, s;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v >> w >> s;
        if (s == 0)
        {
            a[num] = v;
            b[num] = w;
            c[num++] = 0; // type
        }
        else if (s == -1)
            s = 1;
        int k = 1;
        while (s >= k)
        {
            a[num] = k * v;
            b[num] = k * w;
            c[num++] = 1;
            s -= k;
            k <<= 1;
        }
        if (s)
        {
            a[num] = s * v;
            b[num] = s * w;
            c[num++] = 1;
        }
    }
    for (int i = 1; i < num; i++)
    {
        if (c[i] == 1)
            for (int j = m; j >= a[i]; j--)
                f[j] = max(f[j], f[j - a[i]] + b[i]);
        else
            for (int j = a[i]; j <= m; j++)
                f[j] = max(f[j], f[j - a[i]] + b[i]);
    }
    cout << f[m] << endl;
    return 0;
}