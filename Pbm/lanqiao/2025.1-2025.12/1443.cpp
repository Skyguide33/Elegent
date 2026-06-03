//2025/2/14
#include <iostream>
using namespace std;



int main()
{
  int card[10], t, i;
  for(i = 0; i < 10; i++) card[i] = 2021;
  bool end = 0;
  for(i = 1; !end; i++) {
    t = i;
    while(t) { 
      if(card[t%10] > 0) card[t%10]--;
      else {
        end = 1;
        break;
      }
      t /= 10;
    }
  }
  cout << i-1 << endl;
  return 0;
}