//
#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
using ll = long long;
const int N = 2e5 + 5;

int mat[105][105];



void gauss(int n) {
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (j < i && mat[j][j])continue;
			if (mat[j][i]) {
				swap(mat[i], mat[j]);
				break;
			}
		}
		if (mat[i][i]) {
			for (int j = 1;j <= n;j++) {
				if (i != j && mat[j][i]) {
					for (int k = i;k <= n + 1;k++)
						mat[j][k] ^= mat[i][k];
				}
			}
		}
	}
}

void print(int n) {
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n + 1;j++)
			cout << mat[i][j] << " \n"[j == n + 1];
}

signed main() {
	mat[1][1] = 1; mat[1][2] = 1; mat[1][3] = 1; mat[1][4] = 0; mat[1][5] = 0;
	mat[2][1] = 1; mat[2][2] = 0; mat[2][3] = 1; mat[2][4] = 1; mat[2][5] = 1;
	mat[3][1] = 0; mat[3][2] = 1; mat[3][3] = 1; mat[3][4] = 1; mat[3][5] = 1;
	mat[4][1] = 0; mat[4][2] = 0; mat[4][3] = 1; mat[4][4] = 1; mat[4][5] = 0;
	gauss(4);
	print(4);
	cout << '\n';
	mat[1][1] = 1; mat[1][2] = 1; mat[1][3] = 0; mat[1][4] = 1;
	mat[2][1] = 1; mat[2][2] = 0; mat[2][3] = 1; mat[2][4] = 1;
	mat[3][1] = 0; mat[3][2] = 1; mat[3][3] = 1; mat[3][4] = 1;
	gauss(3);
	print(3);
	cout << '\n';
	mat[1][1] = 1; mat[1][2] = 0; mat[1][3] = 1; mat[1][4] = 1; mat[1][5] = 0;
	mat[2][1] = 0; mat[2][2] = 1; mat[2][3] = 1; mat[2][4] = 1; mat[2][5] = 0;
	mat[3][1] = 1; mat[3][2] = 1; mat[3][3] = 0; mat[3][4] = 0; mat[3][5] = 0;
	mat[4][1] = 0; mat[4][2] = 0; mat[4][3] = 1; mat[4][4] = 1; mat[4][5] = 1;
	gauss(4);
	print(4);
	return 0;
}