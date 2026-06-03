#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int N = 2e5 + 5;

int n, w[N];
struct node
{
    int l, r, sum;
} tr[N * 4];

void build(int p, int l, int r)
{
    tr[p] = {l, r, w[l]}; // w[l]:叶子节点的值
    if (l == r)
        return;
    int m = l + r >> 1;
    build(p << 1, l, m);
    build(p << 1 | 1, m + 1, r);
    tr[p].sum = tr[p << 1].sum + tr[p << 1 | 1].sum;
}
// 点修改
void update(int p, int x, int k)
{
    if (tr[p].l == x && tr[p].r == x)
    {
        tr[p].sum += k;
        return;
    }
    int m = tr[p].l + tr[p].r >> 1;
    if (x <= m)
        update(p << 1, x, k);
    else
        update(p << 1 | 1, x, k);
    tr[p].sum = tr[p << 1].sum + tr[p << 1 | 1].sum;
}
// 区间查询
int query(int p, int x, int y)
{
    if (x <= tr[p].l && tr[p].r <= y)
        return tr[p].sum;
    int m = tr[p].l + tr[p].r >> 1;
    int sum = 0;
    if (x <= m)
        sum += query(p << 1, x, y);
    if (y > m)
        sum += query(p << 1 | 1, x, y);
    return sum;
}
signed main()
{

    return 0;
}