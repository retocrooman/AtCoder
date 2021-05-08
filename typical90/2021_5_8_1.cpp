#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
const int mod = 1000000007;

int main() {
    int N;
    string S;
    cin >> N >> S;
    vector<vector<int>> dp(N+1,vector<int>(8));
    string str={"atcoder"};
    dp.at(0).at(0) = 1;
    rep(i,N) {
        rep(j,8) {
            dp.at(i+1).at(j) += dp.at(i).at(j);
            char c = S.at(i);
            if (c==str.at(0) && j==0) dp.at(i+1).at(j+1) = dp.at(i).at(j);
            if (c==str.at(1) && j==1) dp.at(i+1).at(j+1) = dp.at(i).at(j);
            if (c==str.at(2) && j==2) dp.at(i+1).at(j+1) = dp.at(i).at(j);
            if (c==str.at(3) && j==3) dp.at(i+1).at(j+1) = dp.at(i).at(j);
            if (c==str.at(4) && j==4) dp.at(i+1).at(j+1) = dp.at(i).at(j);
            if (c==str.at(5) && j==5) dp.at(i+1).at(j+1) = dp.at(i).at(j);
            if (c==str.at(6) && j==6) dp.at(i+1).at(j+1) = dp.at(i).at(j);
        }
        rep(j,8) dp.at(i+1).at(j) %= mod;
    }
    cout << dp.at(N).at(7) << endl;
}