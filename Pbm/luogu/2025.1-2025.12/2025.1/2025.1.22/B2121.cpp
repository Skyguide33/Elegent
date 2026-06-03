//2025/1/21
#include <iostream>
#include <cstring>
using namespace std;

#if 1
int main() {
  char input[30001], maxch[101] = {}, minch[102] = {};
  unsigned length = 0, len = 0;
  cin.getline(input, 30000);
  while(input[length]) length++;
  maxch[0] = minch[101] = '\0';
  for(int i = 0; i < 101; i++) minch[i] = '3';
  for(unsigned i = 0; i <= length ; i++) {
    if(input[i] != ' ' && input[i] != ',' && input[i] != '.' && input[i] != '\0') len++;
    else {
      if(len != 0) {
        if(len > strlen(maxch)) {
          for(unsigned j = 0; j < len; j++) maxch[j] = input[i-len+j];
          maxch[len] = '\0';
        }
        if(len < strlen(minch)) {
          for(unsigned j = 0; j < len; j++) minch[j] = input[i-len+j];
          minch[len] = '\0';
        }
      }
      len = 0;
    }
  }
  cout << maxch << endl << minch << endl;
  return 0;
}
#endif
#if 0
int main() {
  char input[30001], max[101], min[101], d[4] = ",. ", *token;
  cin.getline(input, 30000);
  token = strtok(input, d);
  strcpy(max, token);
  strcpy(min, token);
  while(token) {
    if(strlen(token) > strlen(max)) strcpy(max, token);
    if(strlen(token) < strlen(min)) strcpy(min, token);
    token = strtok(NULL, d);
  }
  cout << max << endl << min << endl;
}
#endif