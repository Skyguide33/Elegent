#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <random>
#define ll long long
#define ull unsigned long long
#define lll __int128
//#pragma GCC target("avx")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize(2)

/*------------------------------Base------------------------------*/

inline ll mul(ll a, ll b, const ll M){
	ll d =a*(long double)b/M;
	ll ret =a*b-d*M;
	if(ret < 0)
		ret +=M;
	if(ret >= M)
		ret -=M;
	return ret;
}

inline ll plus2(ll a, ll b, const ll M){
	ll d =(a+(long double)b)/M+0.5;
	ll ret =a+b-d*M;
	if(ret < 0)
		ret +=M;
	return ret;
}

inline ll plus(const lll a, const lll b, const lll M){
	lll c =a+b;
	if(c >= M)
		return c-M;
	else
		return c;
}

ll Pow(ll x, ll k, const ll M){
	ll ret =1;
	for(; k; x =mul(x, x, M), k >>=1) if(k&1) ret =mul(ret, x, M);
	return ret;
}

ll gcd(ll a, ll b){
	while(b) b ^=a ^=b ^=a %=b;
	return a;
}

inline ll Abs(ll x){ return (x < 0) ? -x : x; }

/*------------------------------Rand------------------------------*/

static std::mt19937 engine;

/*------------------------------Miller Robin------------------------------*/

bool mr(ll p){
	if(p < 2) return 0;
	if(p == 2) return 1;
	if(p == 3) return 1;
	std::uniform_int_distribution<ll> Rand(2, p-2);
	ll d =p-1, r =0;
	while(!(d&1)) ++r, d >>=1;
	for(ll k =0; k < 10; ++k){
		/*[2, p-2]*/
		ll a =Rand(engine);
		ll x =Pow(a, d, p);
		if(x == 1 || x == p-1) continue;
		for(int i =0; i < r-1; ++i){
			x =mul(x, x, p);
			if(x == p-1) break;
		}
		if(x != p-1) return 0;
	}
	return 1;
}

/*------------------------------Pollard Rho------------------------------*/

using std::min;

/*貌似 -c 在本题的数据的效率高些 (0.2s)，原因尚不确定*/
inline ll getnext(ll x, ll c, ll n){ return plus(mul(x, x, n), -c, n); }

ll pr(ll n){
	/*因为初始跳两步的原因，下面写法均没法分解 4 (即使下面的 Rand 范围设置为 [0, n-1] )*/
	if(n == 4) return 2;
	std::uniform_int_distribution<ll> Rand(3, n-1);
	ll x =Rand(engine), y =x;
	ll c =Rand(engine);
	ll d =1;
	
	/*以下两种写法的期望复杂度都是正确的，但写法 1 的表现更好*/
	
	/*----------写法 1----------*/
	
	x =getnext(x, c, n);
	y =getnext(y, c, n), y =getnext(y, c, n);
	for(int lim =1; x != y; lim =min(128, lim<<1)){/*提升约 0.1s */
//	for(int lim =1; x != y; lim =lim<<1){
		ll cnt =1;
		for(int i =0; i < lim; ++i){
			ll tmp =mul(cnt, Abs(plus(x, -y, n)), n);
			if(!tmp)/*提升约 0.6s；这时要么原先的 cnt 含 n 质因数 (这时 x-y 也含 )，要么 x-y == 0*/
				break;
			cnt =tmp;
			x =getnext(x, c, n);
			y =getnext(y, c, n), y =getnext(y, c, n);
		}
		d =gcd(cnt, n);
		if(d != 1)
			return d;
	}
	return n;
	
	/*----------写法 2----------*/
	/*这里还加了倍增 gcd 优化，可以作为参考*/
	
	/*
	x =getnext(x, c, n);
	y =getnext(y, c, n), y =getnext(y, c, n);
	ll x2 =x, cnt =1;
	for(int i =1, i2 =1, k =2, lim =1; x != y; ++i, ++i2){
		x =getnext(x, c, n);
		y =getnext(y, c, n), y =getnext(y, c, n);
	//	d =gcd(Abs(plus(x, -x2, n)), n);
		ll tmp =mul(cnt, Abs(plus(x, -x2, n)), n);
		if(tmp)
			cnt =tmp;
		if(i2 == lim || !tmp || x == y){
			i2 =1;
			lim =min(128, lim<<1);
			d =gcd(cnt, n);
			if(d != 1)
				return d;
			cnt =1;
		}
	//	if(d != 1)
	//		return d;
		if(i == k){
			x2 =x;
			k <<=1;
		}
	}
	return n;*/
}

ll mxp;

inline void push(ll p){
	if(p > mxp)
		mxp =p;
}

/*函数要求保证 n 可分解*/
void dfs(ll n){
	srand(time(0));
	ll d =pr(n), d2;
	while(d == n)
		d =pr(n);
	d2 =n/d;
	if(mr(d))
		push(d);
	else
		dfs(d);
	if(mr(d2))
		push(d2);
	else
		dfs(d2);
}

ll getfact(ll n){
	mxp =0;
	if(mr(n))
		return n;
	else
		dfs(n);
	return mxp;
}

/*------------------------------Main------------------------------*/

inline ll read(){
	ll x =0; char c =getchar();
	while(c < '0' || c > '9') c =getchar();
	while(c >= '0' && c <= '9') x = (x<<3) + (x<<1) + (48^c), c =getchar();
	return x;
}

int main(){
	srand(time(0));
	for(int t =0, T =read(); t < T; ++t){
		ll n =read();
		ll fact =getfact(n);
		if(fact == n)
			puts("Prime");
		else
			printf("%lld\n", fact);
	}
}
