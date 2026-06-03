#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
  int N;
  cin>>N;
  vector<int> H(N), ans;
  map<int,int> Map;
  for(int i=0;i<N;i++){
      cin>>H[i];
      Map[H[i]]+=1;
  }  

  sort(H.begin(), H.end());

  for(int g=H[N-1];g>=1;g--){
      
      
    for(int i=g;i<=H[N-1];i+=g){
        int count=Map[i];
        while(count--){
            ans.push_back(i);
            if(ans.size()==3){
                  cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<endl;
                  return 0;
            }
          }
    }
    ans.clear();
}
  
  return 0;
}