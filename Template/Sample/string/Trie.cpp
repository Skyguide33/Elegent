//
#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
using ll = long long;
const int N = 3e6 + 5;

int ch[N][65];
int cnt[N], idx;

int num(char& c) {
    if (c >= 'A' && c <= 'Z')
        return c - 'A';
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 26;
    return c - '0' + 52;
}

void insert(string& s) {
    int p = 0;
    for (int i = 0;s[i];i++) {
        int j = num(s[i]);
        if (!ch[p][j])ch[p][j] = ++idx;
        p = ch[p][j];
        cnt[p]++;
    }
}

int qry(string& s) {
    int p = 0;
    for (int i = 0;s[i];i++) {
        int j = num(s[i]);
        if (!ch[p][j])return 0;
        p = ch[p][j];
    }
    return cnt[p];
}

void init() {
    memset(ch, 0, sizeof ch);
    memset(cnt, 0, sizeof cnt);
    idx = 0;
}

signed main() {
    int tt = 1;
    cin >> tt;
    while (tt--) {
        int n, q;
        cin >> n >> q;
        for (int i = 0;i <= idx;i++)
            for (int j = 0;j < 65;j++)
                ch[i][j] = 0;
        for (int i = 0;i <= idx;i++)
            cnt[i] = 0;
        idx = 0;
        string s;
        for (int i = 1;i <= n;i++) {
            cin >> s;
            insert(s);
        }
        for (int i = 1;i <= q;i++) {
            cin >> s;
            cout << qry(s) << '\n';
        }
    }
    return 0;
}