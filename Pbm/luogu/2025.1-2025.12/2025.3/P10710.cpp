//2025/3/5 School Photo
#include <bits/stdc++.h>
using namespace std;

struct Student{
  int cls, h;
};

int n, s, ans = 1e9, top, l, r, sum, cnt[1005];
Student a[1000005];

void move_l() {
  if(a[r].h-a[l].h < ans) ans = a[r].h - a[l].h;
  cnt[a[l].cls]--;
  if(!cnt[a[l++].cls]) sum--;
  return;
}

void move_r() {
  if(!cnt[a[++r].cls]) sum++;
  cnt[a[r].cls]++;
}

bool cmp(Student x, Student y) {
  return (x.h < y.h);
}

int main() {
  cin >> n >> s;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= s; j++) {
      a[++top].cls = i;
      cin >> a[top].h;
    }
  }
  sort(a+1, a+top+1, cmp);
  l = 1; r = 0;
  while(l <= top && r <= top) {
    if(sum >= n) move_l();
    else move_r();
  }
  cout << ans << endl;
}=