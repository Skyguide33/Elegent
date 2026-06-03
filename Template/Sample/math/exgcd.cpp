// 裴蜀定理
// 如果a和b是不全为0的整数，则有整数x、y，使得ax + by = gcd(a,b)

// 裴蜀定理推论
// 1，如果a和b是不全为0的整数，a和b互质，当且仅当存在整数x、y，使ax + by = 1
// 2，如果a和b是不全为0的整数，并且ax + by = c有解，那么c一定是gcd(a,b)的整数倍
// 3，a和b两项的裴蜀定理，可以推广到多项的情况

// 如果ax + by = c一旦有解，就意味着一定有无穷多组(x,y)，都可以使得式子成立

#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
using ll = long long;
const int N = 2e5 + 5;
#define int ll
// 扩展欧几里得算法
// 对于方程ax + by = gcd(a,b)
// 当a和b确定，那么gcd(a,b)也确定
// 扩展欧几里得算法可以给出a和b的最大公约数d、以及其中一个特解x、y
// 特别注意要保证入参a和b没有负数
int x, y, px, py, d;
void exgcd(int a, int b) {
    if (b == 0) {
        x = 1;
        y = 0;
        d = a;
    } else {
        exgcd(b, a % b);//a-a/b*b;
        px = x;
        py = y;
        x = py;
        y = px - py * (a / b);
    }
}

ll qpow(int a, int b, int mod);

signed main() {
    //exgcd求逆元，mod可以不是质数，但二者需互质
    int num, mod;
    cin >> num >> mod;
    exgcd(num, mod);
    x = (x % mod + mod) % mod;
    cout << x << '\n';
    // cout << qpow(num, mod - 2, mod) << '\n';
    return 0;
}

ll qpow(int a, int b, int mod) {
    ll res = 1;
    while (b) {
        if (b & 1)res = 1LL * res * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return res;
}