// #include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;

const int N = 5e4 + 5;

int head[N];
int ne[N * 2];
int to[N * 2];
int cnt = 1;
int n;
void add(int u, int v) {
    ne[cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt++;
}

int sz[N], son[N];//sz数组更新结束后是以1为根的大小

void dfs(int u, int f) {
    sz[u] = 1;
    son[u] = 0;
    for (int e = head[u];e != 0;e = ne[e]) {
        int v = to[e];
        if (v == f)continue;
        dfs(v, u);
        son[u] = max(son[u], sz[v]);
        sz[u] += sz[v];
    }
    son[u] = max(son[u], n - sz[u]);
}

void solve() {
    scanf("%d", &n);
    // cin >> n;
    for (int i = 1;i <= n;i++)head[i] = 0;
    cnt = 1;
    int u, v;
    for (int i = 1;i < n;i++) {
        scanf("%d%d", &u, &v);
        // cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dfs(1, 0);
    vector<int>a(2);
    int m = 0;
    for (int i = 1;i <= n;i++)
        if (son[i] <= n / 2)
            a[m++] = i;

    for (int i = 0;i < m;i++) {
        if (i)putchar(' ');
        printf("%d", a[i]);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}