//2025/2/17
#include<iostream>
#define rint register int
using namespace std;
long long n,a[100001],q[100001],sum[100001],f[100001],ans,tail; 
/*a[100001] 存储每一天的感受值，
sum[100001] 存储前缀和，
f[100001] 存储以第i天为最低点的最大面积，
q[100001] 存储单调递减的感受值的下标，
tail 存储q的尾部下标，
ans 存储最大面积 */

int main()
{
    scanf("%lld",&n);
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
    n++;a[n]=0;
    for (int i=1;i<=n;i++) 
    {
        sum[i]=sum[i-1]+a[i];
        //初始tail=0，q[0]=0
        while (a[q[tail]]>a[i])
        {
            f[q[tail]]+=(sum[i-1]-sum[q[tail]]);
            tail--;
        }
        f[i]=sum[i]-sum[q[tail]];
        q[++tail]=i;
        // cout << "i = " << i << ", tail = " << tail << endl;
        // cout << "a[]:   ";
        // for(int j = 0; j <= i; j++) cout << a[j] << '\t';
        // cout << endl << "sum[]: ";
        // for(int j = 0; j <= i; j++) cout << sum[j] << '\t'; 
        // cout << endl << "q[]:   ";
        // for(int j = 0; j <= tail; j++) cout << q[j] << '\t';
        // cout << endl << "f[]:   ";
        // for(int j = 0; j <= i; j++) cout << f[j] << '\t';
        // cout << endl << endl;

    }
    for (int i=1;i<=n-1;i++) ans=max(ans,f[i]*a[i]);
    printf("%lld\n",ans);
}



