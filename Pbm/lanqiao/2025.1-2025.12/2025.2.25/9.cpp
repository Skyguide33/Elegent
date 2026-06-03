#include <iostream>
using namespace std;

int a[100005];
int main() {
    int n, ans = 0, maxnum = -1;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] > maxnum) {
            maxnum = a[i];
            ans++;
        } 
    }
    cout << ans << endl;
    return 0;
}