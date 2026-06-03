//2025/1/23
#include <iostream>
#include <vector>
using namespace std;

char C[3][3];
string same(char a, char b, char c) {
  string res;
  if(a == b && b == c) {
    res += a;
  }
  else if(a == c || b == c) {
    if(a < b) {
      res += a;
      res += b;
    }
    else {
      res += b;
      res += a;
    }
  }
  else if(a == b) {
    if(a < c) {
      res += a;
      res += c;
    }
    else {
      res += c;
      res += a;
    }
  }
  else res = "0";
  return res;
}
void pushback(vector<string>&arr, string res) {
  bool sap = 0;
  for(string& x: arr) {
    if(x == res) {
      sap = 1;
      break;
    }
  }
  if(!sap) arr.push_back(res);
}
int main() {
  vector<string>sin;
  vector<string>dlb;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      cin >> C[i][j];
    }
  }
  string res;
  for(int i = 0; i < 3; i++) {
    res = same(C[i][0],C[i][1],C[i][2]);
    if(res != "0") {
      if(res.length() == 1) pushback(sin, res);
      else pushback(dlb, res);
    }
  }
  for(int j = 0; j < 3; j++) {
    string res;
    res = same(C[0][j],C[1][j],C[2][j]);
    if(res != "0") {
      if(res.length() == 1) pushback(sin, res);
      else pushback(dlb, res);
    }
  }
  res = same(C[0][0], C[1][1], C[2][2]);
  if(res != "0") {
    if(res.length() == 1) pushback(sin, res);
    else pushback(dlb, res);
  }
  res = same(C[0][2], C[1][1], C[2][0]);
  if(res != "0") {
    if(res.length() == 1) pushback(sin, res);
    else pushback(dlb, res);
  }
  cout << sin.size() << endl << dlb.size() << endl;
  return 0;
}