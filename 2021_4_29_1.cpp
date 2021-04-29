#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

int main()
{
    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    vector<string> vec = {"dream", "dreamer", "erase", "eraser"};
    rep(i,4) reverse(vec.at(i).begin(), vec.at(i).end());
    bool can1 = false;
    int number = 0;
    while(true) {
        bool can2 = false;
        rep(i,4) {
            if(S.size()-number >= vec.at(i).size()){
                bool can3 = true;
                rep(j,vec.at(i).size()) {
                    if(S.at(j+number) != vec.at(i).at(j)){
                        can3 = false;
                    }
                }
                if(can3){
                    can2 = true;
                    number += vec.at(i).size();
                }
            }
        }
        if(!can2) break;
        if(number == S.size()){
            can1 = true;
            break;
        }
    }
    if(can1) cout << "YES" << endl;
    else cout << "NO" << endl;
}