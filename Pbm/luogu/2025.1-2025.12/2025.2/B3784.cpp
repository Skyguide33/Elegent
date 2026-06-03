//2025/2/9
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long n, m, a ,b, t, fav = 0, favscr = 0;
  scanf("%lld %lld %lld %lld", &n, &m, &a, &b);
  long long Sum[n] = {};
  for(long long i = 0; i < a; i++) {
    for(long long j = 0; j < n; j++) {
      scanf("%lld", &t);
      Sum[j] += t;
      if(i == b-1) {
        if(t > favscr) {
          favscr = t;
          fav = j;
        }
      }
    }
  }
  // for(long long& x: Sum) cout << x << ' ';
  // cout << endl;
  vector<long long>Play;
  for(long long i = 0; i < m; i++) {
    long long maxscr = 0, max = 0;
    for(long long j = 0; j < n; j++) {
      if(Sum[j] > maxscr) {
        maxscr = Sum[j];
        max = j;
      }
    }
    Play.push_back(max);
    Sum[max] = 0;
  }
  bool IsInclude = 0;
  long long i = 0;
  for(; i < m; i++) {
    if(fav == Play[i]) {
      IsInclude = 1;
      break;
    }
  }
  if(IsInclude) {
    Play.erase(Play.begin() + i);
    Play.insert(Play.begin(), fav);
  } else Play[m-1] = fav;

  for(auto& x: Play) printf("%lld ", x+1);
  printf("\n");
  return 0;
}