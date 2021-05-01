#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    int cnt=0;
    cin >> str;
    for (int i; i<9; i++) {
        if(str.substr(i,4) == "ZONe") {
            cnt++;
        }
    }
    cout << cnt << endl;
} 
