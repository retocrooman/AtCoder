#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    if (N%2==1) return 0;
    vector<char> vec={'(', ')'};
    for (int i=0; i<1<<N; i++) {
        string str = "";
        int dep = 0;
        bool can = true;
        for (int j=N-1; j>=0; j--) {
            if ((i & (1<<j)) == 0) {
                str += vec.at(0);
                dep++;
            } else {
                str += vec.at(1);
                dep--;
            }
            if (dep<0) can = false;
        }
        if (can && dep == 0) cout << str << endl;
    }
}