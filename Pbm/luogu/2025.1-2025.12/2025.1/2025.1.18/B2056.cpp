//2025/1/18
#include <iostream>
#include <format>
using namespace std;

int main() {
  int n, num, sum = 0;
  double avg;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> num;
    sum += num;
  }
  avg = double(sum) / n;
  cout << sum << ' ';
  cout.precision(5);
  cout << fixed << avg;
  return 0;
}