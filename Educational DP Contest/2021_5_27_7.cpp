#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;
const ll mod = 1000000007;
const double pi=3.1415926535;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    int H,W;
    cin >> H >> W;
    vector<vector<char>> a(H+1, vector<char>(W+1));
    REP(i, H) {
        REP(j, W) cin >> a.at(i).at(j);
    }

    vector<vector<ll>> dp(H+1, vector<ll>(W+1));
    dp.at(1).at(1) = 1;
    rep(i, H) {
        rep(j, W) {
            if (i == 0 && j == 0) continue;
            if (a.at(i+1).at(j+1) == '#') dp.at(i+1).at(j+1) = 0;
            else dp.at(i+1).at(j+1) = dp.at(i+1).at(j) + dp.at(i).at(j+1);
            dp.at(i+1).at(j+1) %= mod;
        }
    }
    
    cout<< dp.at(H).at(W) << endl;
}