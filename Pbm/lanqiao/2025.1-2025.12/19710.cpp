#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
  int n;
  string d;
  cin >> n >> d;
  reverse(d.begin(), d.end());
  while(n--) {
    int r = 0;
    for(unsigned i = 0; i < d.length(); i++) {
      if(d.at(i) == '.') continue;
      r += (d.at(i) - '0') * 2;
      d.at(i) = (r % 10) + '0';
      r /= 10;
    }
    if(r) {
      d.push_back(r + '0');
    }
  }
  reverse(d.begin(), d.end());
  int point = d.find('.');
  if(d.at(point+1) >= '5') d.at(point-1) += 1;
  d = d.substr(0, point);
  cout << d << endl;
  return 0;
}