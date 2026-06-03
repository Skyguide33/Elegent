//2025/1/20
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int T;
  cin >> T;
  while(T--) {
    long long n;
    cin >> n;

    if(n % 4 == 0) {
      cout << "Yes" << endl;
      continue;
    }
    vector<long long>num;
    while(n) {
      num.push_back(n%10);
      n /= 10;
    }
    reverse(num.begin(), num.end());
    bool find = 0;
    for(int i = 0; i < num.size() && !find; i++) {
      for(int j = i+1; j <= num.size() && !find; j++) {
        auto temp = num;
        temp.erase(temp.begin()+i, temp.begin()+j);
        if(temp.empty()) continue;
        long long t = 0;
        for(auto &x: temp) t = t*10 + x;
        if(t % 4 == 0) find = 1;
      }
    }
    cout << (find?"Yes": "No") << endl;
    // if(num.front() % 2) {
    //   while(num.size() > 1 && ((num.at(1)*10+num.front()) % 4)) num.erase(num.begin());
    //   if((num.size() == 1 && (num.front() % 4))) cout << "No";
    //   else cout << "Yes";
    //   cout << endl;
    //   continue;
    // }
    // bool find = 0;
    // while(!num.empty() && !find) {
    //   for(unsigned i = 0; i < num.size(); i++) {
    //     if(!((num.front()+num.at(i)*10) % 4)) {
    //       find = 1;
    //       break;
    //     }
    //   }
    //   num.erase(num.begin());
    // }
    // if(find) cout << "Yes";
    // else cout << "No";
    // cout << endl;
  }
  return 0;
}