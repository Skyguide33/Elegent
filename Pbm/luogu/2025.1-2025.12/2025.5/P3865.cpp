//2025/5/28
#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define max(x, y) (x>y? x: y)

int a[N], n, m, LOG2[N], max_n[N][22];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int main() {
  cout.tie(0) -> sync_with_stdio(0);
  n = read(), m = read();
  for(int i = 1; i <= n; ++i) max_n[i][0] = read();
  LOG2[0] = -1;
  for(int i = 1; i <= n; ++i) {
    LOG2[i] = LOG2[i>>1]+1;
  }
  for(int i = 1; i <= LOG2[n]; ++i) {
    for(int s = 1; s <= n; ++s) {
      max_n[s][i] = max(max_n[s][i-1], max_n[s+(1<<(i-1))][i-1]);
    }
  }
  while(m--) {
    int l = read(), r = read();
    int len = LOG2[r-l+1];

    cout << max(max_n[l][len], max_n[r+1-(1<<len)][len]) << endl;
  }
  return 0;
}