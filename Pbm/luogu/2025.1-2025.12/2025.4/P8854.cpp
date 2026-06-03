//2025/4/
#include <bits/stdc++.h>
using namespace std;

int N, P[101], Q[101], vis[203][203], oft = 101;

int main() {
	cin.tie(0) -> sync_with_stdio(0);
	int K; cin >> K;
	while(K--) {
		bool can = 0;
		memset(vis, 0, sizeof(vis));
		cin >> N;
		for(int i = 1; i <= N; i++) cin >> P[i] >> Q[i];
		queue<tuple<int,int>> q;
		q.push({P[1], Q[1]});
		vis[oft+P[1]][oft+Q[1]] = 1;
		while(q.size()) {
			auto& [x, y] = q.front(); q.pop(); 
			for(int i = 1; i <= N; i++) {
				int nx = x+P[i], ny = y+Q[i];
				if(abs(nx) > 100 || abs(ny) > 100 || vis[oft+nx][oft+ny]) continue;
				q.push({nx, ny});
				vis[oft+nx][oft+ny] = 1;
			}
			if(vis[oft-1][oft] && vis[oft][oft+1] && vis[oft+1][oft] && vis[oft][oft-1]) {
				can = 1; break;
			}
		}
		if(can) cout << "TAK" << endl;
		else cout << "NIE" << endl;
	}

	return 0;
}