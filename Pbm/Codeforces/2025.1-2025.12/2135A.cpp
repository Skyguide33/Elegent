#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;

int T, n, a[MAXN], dp[MAXN]; queue<int> q[MAXN];

int main() {
	for (scanf("%d", &T); T--; ) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) q[i] = {};
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) {
			dp[i] = dp[i - 1], q[a[i]].push(i);
			if (q[a[i]].size() == a[i]) {
				dp[i] = max(dp[i], dp[q[a[i]].front() - 1] + a[i]);
				q[a[i]].pop();
			}
		}
		printf("%d\n", dp[n]);
	}
}