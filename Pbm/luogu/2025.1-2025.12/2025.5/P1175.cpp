//2025/5/9
#include <bits/stdc++.h>
using namespace std;

vector<char> q;
stack<char> st;
map<char, int> mp = {{'+', 0}, {'-', 0}, {'*', 1}, {'/', 1}, {'^', 2}};
char s[101]; int p = 0;

void getep(int stlen) {
  while(p < strlen(s)) {
    if(isdigit(s[p])) {
      q.push_back(s[p]);
      q.push_back(' ');
    }
    else if(s[p] == '(') {
      ++p;
      getep(st.size());
    } else if(s[p] == ')') {
      while(st.size() > stlen) {
        q.push_back(st.top()); 
        st.pop();
        q.push_back(' ');
      }
      return;
    } else {
      while(st.size() > stlen && mp[st.top()] >= mp[s[p]]) {
        if(s[p] == '^' && st.top() == '^')  break;
        q.push_back(st.top()); 
        st.pop();
        q.push_back(' ');
      }
      st.push(s[p]);
    }
    ++p;
  }
  if(p == strlen(s)) {
    while(!st.empty()) {
      q.push_back(st.top()); 
      st.pop();
      q.push_back(' ');
    }
  }
}

void process(){
  int p1, p2, num1=0, num2=0, res;
  char opt;
  for(int i = 0;; ++i) {
    if(!isdigit(q[i]) && q[i] != ' ') {
      if(q[i] == '-' && isdigit(q[i+1])) continue;
      opt = q[i];
      p1 = i-2;
      while(isdigit(q[p1])) {
        num2 += (q[p1]-'0') * pow(10, i-2-p1);
        --p1;
      }
      if(q[p1] == '-') {
        num2 *= -1;
        --p1;
      }
      p2 = p1-1;
      while(p2 != -1 && isdigit(q[p2])) {
        num1 += (q[p2]-'0') * pow(10, p1-1-p2);
        --p2;
      }
      if(p2 != -1 && q[p2] == '-') {
        num1 *= -1;
        --p2;
      }
      while(i > p2) {
        q.erase(q.begin()+p2+1);
        --i;
      }

      if(opt == '+') {
        res = num1+num2;
      } else if(opt == '-') {
        res = num1-num2;
      } else if(opt == '*') {
        res = num1*num2;
      } else if(opt == '/') {
        res = num1/num2;
      } else {
        res = pow(num1, num2);
      }
      if(res < 0) {
        q.insert(q.begin()+p2+1, '-');
        res *= -1;
        ++p2;
      }
      if(res == 0) q.insert(q.begin()+p2+1, '0');
      else {
        while(res) {
          q.insert(q.begin()+p2+1, res%10+'0');
          res /= 10;
        }
      }
      return;
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> s;
  getep(0);
  for(int i = 0; i < q.size(); ++i) {
    cout << q[i];
  }
  cout << endl;
  while(!isdigit(q[q.size()-2])) {
    process();
    for(int i = 0; i < q.size(); ++i) {
      cout << q[i];
    }
    cout << endl;
  }
  return 0;
}