//2025/2/15
#include <iostream>
#include <iomanip>
using namespace std;

int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main() {
  long long T, x, yy, MM, dd, HH, mm, past, max, gap, gapH;
  string date, time;
  cin >> T;
  for(int k = 0; k < T; k++) {
    past = 0, max = 0;
    cin >> date >> time >> x;
    yy = stoi(date.substr(0, 4));
    MM = stoi(date.substr(5, 2)); 
    dd = stoi(date.substr(8, 2)); 
    HH = stoi(time.substr(0, 2)); 
    mm = stoi(time.substr(3, 2)); 
    for(int y = 1970; y < yy; y++) {
      if((y % 4 == 0 && y % 100) || y % 400 == 0) past += 366 * 1440;
      else past += 365 * 1440;
    }
    for(int M = 1; M < MM; M++) {
      past += (month[M]) * 1440;
      if(M == 2 && ((yy % 4 == 0 && yy % 100) || yy % 400 == 0)) past += 1440;
    }
    past += (dd-1)*1440 + HH*60 + mm;
    //cout << "past = " << past << " , " << past / 1440 << "days" << endl;
    max = past - 1000;
    while(max % x) max++;
    while(max <= past) max += x;
    max -= x;
    gap = past - max;
    if(mm >= gap) mm -= gap;
    else {
      gap -= mm;
      if(gap % 60) {
        gapH = gap / 60 + 1;
        gap %= 60;
        mm = 60 - gap;
      }
      else {
        gapH = gap / 60;
        mm = 0;
      }
      if(HH >= gapH) HH-= gapH;
      else {
        gapH -= HH;
        HH = 24 - gapH;
        if(dd > 1) {
          dd--;
        }
        else {
          if(MM > 1) {
            MM--;
            dd = month[MM];
            if(MM == 2 && ((yy % 4 == 0 && yy % 100) || yy % 400 == 0)) dd++;
          }
          else {
            yy--;
            MM = 12;
            dd = 31;
          }
        }
      }
    }
    cout << setfill('0') << yy << '-' << setw(2) << MM << '-' << setw(2) << dd << ' ' << setw(2) << HH << ':' << setw(2) << mm << ':' << "00" << endl;
    

  }
  return 0;
}