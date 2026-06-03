//2025/2/1
#include <iostream>
using namespace std;

int main() {
  int N, max = 0;
  cin >> N;
  pair<int, string> Stu[N];
  for(int i = 0; i < N; i++) {
    cin >> Stu[i].first >> Stu[i].second;
    if(Stu[max].first < Stu[i].first) max = i;
  }
  cout << Stu[max].second << endl;
  return 0;
}