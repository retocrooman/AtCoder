#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

int main()
{
    bool can = true;
    int N;
    cin >> N;
    vector<vector<int>> vec(N, vector<int>(3));
    rep(i,N) cin >> vec.at(i).at(0) >> vec.at(i).at(1) >> vec.at(i).at(2);
    rep(i,N) {
        if (vec.at(i).at(0)%2 != (vec.at(i).at(1)+vec.at(i).at(2))%2) can = false;
    }
    rep(i,N) {
        int a=0, b=0, c=0;
        if (i==0) {
            a = vec.at(i).at(0);
            b = vec.at(i).at(1);
            c = vec.at(i).at(2);
        } else {
            a = vec.at(i).at(0) - vec.at(i-1).at(0);
            b = abs(vec.at(i).at(1) - vec.at(i-1).at(1));
            c = abs(vec.at(i).at(2) - vec.at(i-1).at(2));
        }
        if (a < b+c) can = false;
    }
    if (can) cout << "Yes" << endl;
    else cout << "No" << endl;
}