#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
// #define yes cout << "Yes\n";
// #define no cout << "No\n";
// #define itn int
// #define fro for
// #define ednl endl
// #define retrun return
#define PII pair<ll, ll>
#define int ll
// #define lll __int128

const int N = 1e5 + 5;
const int P = 998244353;
// const int P = 1e9 + 7;

vector<int> e[N];
void solve()
{
	int n;
	cin >> n;
	bool v[N];
	for (int i = 1; i <= n; i++)
		e[i].clear();
	vector<int> w(n + 1);
	vector<PII> a;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		if ((w[u] + 1) / 2 > w[v])
			a.push_back({u, v});
		else if ((w[v] + 1) / 2 > w[u])
			a.push_back({v, u});
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (auto [x, y] : a)
	{
		if (v[x])
			continue;
		v[x] = 1;
		queue<int> q;
		q.push(x);
		while (q.size())
		{
			int t = q.front();
			// cout << t << ' ';
			q.pop();
			for (auto u : e[t])
			{
				if (v[u] || u == y)
					continue;
				v[u] = 1;
				q.push(u);
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		if (!v[i])
			ans++;
	cout << ans << endl;
}
signed main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int TT = 1;
	cin >> TT;

	while (TT--)
	{
		solve();
	}
	// test();
	return 0;
}