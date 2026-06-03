#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define PII pair<ll, ll>
#define int ll
// #define endl '\n'
// #define lll __int128
#define yes cout << "Yes\n"
#define no cout << "No\n"

const int N = 1e7 + 5;
const int P = 998244353;
// const int P = 1e9 + 7;

struct node {
	int l, r, d;
};

int tr[N];

int U = (1 << 30) - 1;
int n, A, B, C;
ll f(int x);
ll g(int x);
ll h(int x);
ll ff[N], gg[N], hh[N];

int lowbit(int x) {
	return x & -x;
}

void add(int i, int v) {
	while (i <= n) {
		tr[i] += v;
		i += lowbit(i);
	}
}

int sum(int i) {
	int res = 0;
	while (i) {
		res += tr[i];
		i -= lowbit(i);
	}
	return res;
}


void solve() {
	cin >> n >> A >> B >> C;
	vector<int>a(n);
	memset(ff, -1, sizeof ff);
	memset(gg, -1, sizeof gg);
	memset(hh, -1, sizeof hh);
	for (int i = 0;i < n;i++) {
		a[i] = i;
	}
	for (int i = 0;i < n;i++) {
		swap(a[i], a[i + (f(i) % (n - i))]);
	}

	// for (auto x : a)cout << x << ' ';
	// cout << '\n';
	ll ans = 0;
	for (int i = n - 1;i >= 0;i--) {
		ans += sum(a[i] + 1);
		add(a[i] + 1, 1);
	}
	cout << ((ans & 1) ? 1 : 0);

	vector<node>qry(n);
	int l, r, d;
	for (int i = 1;i < n;i++) {
		l = min(f(n + 3 * i - 3) % n, f(n + 3 * i - 2) % n);
		r = max(f(n + 3 * i - 3) % n, f(n + 3 * i - 2) % n);
		d = f(n + 3 * i - 1) % n + 1;
		qry[i] = { l,r,d };
	}
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	// per(6000000);
	int TT = 1;
	cin >> TT;
	while (TT--)
		solve();
	return 0;
}


ll f(int x) {
	if (x == -3) {
		return A & U;
	}
	if (x == -2) {
		return B & U;
	}
	if (x == -1) {
		return C & U;
	}
	if (ff[x] != -1)return ff[x];
	return ff[x] = h(x) ^ ((2 * h(x)) & U) ^ f(x - 2) ^ f(x - 1);
}

ll g(int x) {
	if (gg[x] != -1)return gg[x];
	return gg[x] = f(x - 3) ^ (((1 << 16) * f(x - 3)) & U);
}

ll h(int x) {
	if (hh[x] != -1)return hh[x];
	return hh[x] = g(x) ^ (g(x) / (1 << 5));
}