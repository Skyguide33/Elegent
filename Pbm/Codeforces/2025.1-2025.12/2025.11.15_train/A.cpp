
//2025/11/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string op;
  cin>>op;
  string s="";
  if(op=="first"){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
      int tmp;
      cin>>tmp;
      char c = tmp+'a';
      s+=c;
    }
    cout<<s<<'\n';
  }else {
    cin>>s;
    int len = s.size();
    cout<<s.size()<<'\n';
    for(int i=0;i<len;i++){
      cout<<s[i]-'a'<<' ';
    }
  }
  return 0;
}