#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int N = 2e5 + 5;

int p[N], v[N], cnt;
int phi[N];

void get_phi(int n)
{
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!v[i])
            p[cnt++] = i, phi[i] = i - 1;
        for (int j = 0; i * p[j] <= n; j++)
        {
            int m = i * p[j];
            v[m] = 1;
            if (i % p[j] == 0)
            {
                phi[m] = p[j] * phi[i];
                break;
            }
            else
                phi[m] = (p[j] - 1) * phi[i];
        }
    }
}

int _phi(int n)
{
    int res = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            res = res / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        res = res / n * (n - 1);
    return res;
}

signed main()
{
    int n;
    cin >> n;
    get_phi(n);
    for (int i = 1; i <= n; i++)
        printf("%d\n", phi[i]);
    return 0;
}