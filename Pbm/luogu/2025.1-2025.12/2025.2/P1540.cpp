//2025/2/21
#include <iostream>
#include <deque>
using namespace std;

int main() {
  int m, n, Word, AllWords[1001] = {}, ans = 0;
  deque<int>InMemory;
  cin >> m >> n;
  while(n--) {
    cin >> Word;
    if(!AllWords[Word]) {
      if(InMemory.size() >= m) {
        AllWords[InMemory.front()] = 0;
        InMemory.pop_front();
      }
      InMemory.push_back(Word);
      AllWords[Word] = 1;
      ans++;
    }
  } 
  cout << ans << endl;
  return 0;
}
