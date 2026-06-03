#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'
#define yes cout << "Yes\n";
#define no cout << "No\n";
#define retrun return
#define int ll
#define ull unsigned long long
// #define lll __int128
// #define itn int
// #define fro for
// #define ednl endl

const int N = 1e7 + 5;
const int mod = 1e9 + 7;

bool v[N];
int pri[N], cnt = 1;

void era_prime(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (!v[i])
		{
			pri[cnt++] = i;
			for (int j = i * i; j <= n; j += i)
				v[j] = 1;
		}
	}
}

void get_prime(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (!v[i])
			pri[cnt++] = i;
		for (int j = 1; 1LL * i * pri[j] <= n; j++)
		{
			v[i * pri[j]] = 1;
			if (i % pri[j] == 0)
				break; // 整除中断，确保只被最小的质因数划除
		}
	}
}

void solve()
{
	get_prime(1e7);
	cout << cnt << '\n';
}

void test()
{
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int TT = 1;
	// cin >> TT;
	while (TT--)
	{
		solve();
	}
	// test();
	return 0;
}
