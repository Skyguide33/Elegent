#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 1 << 22;
const int g = 3 , gi = 332748118 , mod = 998244353;//不加const时间翻四倍 
ll qw( ll a , ll b ) {
	ll ans = 1;
	while ( b ) {
		if( b & 1 ) {
			ans = ans * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}
int rev[N];
int n , m , l;
ll a[N] , b[N];
void pre( int bit ) {
	for ( int i = 0 ; i < ( 1 << bit ) ; ++i ) {
		rev[i] = (rev[i>>1]>>1)|((i&1)<<(bit - 1));
	}
}
void NTT( ll *F , int len , int on ) {
	for ( int i = 0 ; i < len ; ++i ) {//把递归的底层交换好
		if ( i < rev[i] ) {
			swap( F[i] , F[rev[i]] );
		}
	}
	for ( int i = 2 ; i <= len ; i <<= 1 ) {//枚举步长，从递归的下面往上走 
		ll gn = qw( on ? g : gi , ( mod - 1 ) / ( i ) );
		for ( int j = 0 ; j <= len - 1 ; j += i ) {//走一遍步长 
			ll gg = 1;
			for ( int k = j ; k < j + i / 2 ; ++k ) {//枚举每块区间内的每一个元素
				ll u = F[k];
				ll t = gg * F[k + i / 2] % mod;
				F[k] = (u + t) % mod;
				F[k + i / 2] = ( u - t  + mod ) % mod;
				gg = gg * gn % mod;
			}
		}
	}
	return;
}

int main () {
	int len = 0;
	scanf("%d%d",&n,&m);
	for ( int i = 0 ; i <= n ; ++i ) {
		scanf("%lld",a + i);
	}
	for ( int i = 0 ; i <= m ; ++i ) {
		scanf("%lld",b + i);
	}
	len = n + m;
	int tim = 1;
	l = 0;
	while( tim <= len ) {
		tim <<= 1;
		l++;
	}
	len = tim;
	pre(l);
	NTT( a , len , 1 );
	NTT( b , len , 1 );
	for ( int i = 0 ; i <= len - 1 ; ++i ) {
		a[i] = a[i] * b[i] % mod;
	}
	NTT( a , len , 0 );
	ll inv = qw( len , mod - 2 );
	for ( int i = 0 ; i <= n + m ; ++i ) {
		printf("%lld ",a[i] * inv % mod);
	}
	return 0;
}
