//2025/1/22
#include <iostream>
#include <format>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
#if 0
  string s[m], t[n], dic[n][m];
  for(int i = 0; i < m; i++) cin >> s[i];
  for(int i = 0; i < n; i++) {
    cin >> t[i];
    for(int j = 0; j < m; j++) {
      cin >> dic[i][j];
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(dic[i][j].find(t[i]+".zip/") != 0) {
        //cout << "1 dic[" << i << "][" << j << "]= " << dic[i][j] << endl;
        cout << "Fusu is angry!" << endl;
        continue;
      }
      dic[i][j] = dic[i][j].substr(t[i].length()+5);
      if(dic[i][j].find(t[i]+"/") != 0) {
        //cout << "2 dic[" << i << "][" << j << "]= " << dic[i][j] << endl;
        cout << "Fusu is angry!" << endl;
        continue;
      }
      dic[i][j] = dic[i][j].substr(t[i].length()+1);
      if(dic[i][j].find(s[j]+"/") != 0) {
        //cout << "3 dic[" << i << "][" << j << "]= " << dic[i][j] << endl;
        cout << "Fusu is angry!" << endl;
        continue;
      }
      dic[i][j] = dic[i][j].substr(s[j].length()+1);
      if(dic[i][j].find(s[j]+".cpp") != 0 || dic[i][j].length() != s[j].length()+4) {
        //cout << "4 dic[" << i << "][" << j << "]= " << dic[i][j] << endl;
        cout << "Fusu is angry!" << endl;
        continue;
      }
      cout << "Fusu is happy!" << endl;
    }
  }
  #endif
  #if 1
    string s[m], t[n], pattern;
    for(auto& x: s) cin >> x;
    for(int i = 0; i < n; i++) {
      cin >> t[i];
      for(int j = 0; j < m; j++) {
        cin >> pattern;
        if(pattern == format("{0}.zip/{0}/{1}/{1}.cpp", t[i], s[j])) {
          cout << "Fusu is happy!" << endl;
        } else cout << "Fusu is angry!" << endl;
      }
    }
  #endif
  return 0;
}