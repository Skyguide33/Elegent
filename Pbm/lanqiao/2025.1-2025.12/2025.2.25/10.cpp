#include <iostream>
using namespace std;

int main() {
    string s[4];
    for(int i = 0; i < 4; i++) {
        cin >> s[i];
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 2; j >= i; j--) {
            string s1 = s[j], s2 = s[j+1];
            for(int k = 0; k < s1.length(); k++) {
                if(s1[k] > s2[k]) {
                    cout << s1 << ' ' << s2 << endl;
                    string t = s[j];
                    s[j] = s[j+1];
                    s[j+1] = t;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < 4; i++) cout << s[i];
    cout << endl;
    return 0;
}