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
    int N,W;
    cin >> N >> W;
    vector<pair<int, ll>> wv(N+1);
    REP(i, N) cin >> wv.at(i).first >> wv.at(i).second;

    vector<vector<ll>> dp(N+1, vector<ll>(W+1));
    rep(i, N) {
        rep(j, W+1) dp.at(i+1).at(j) = dp.at(i).at(j);
        rep(j, W+1) {
            if (j - wv.at(i+1).first < 0) continue;
            ll value = dp.at(i).at(j - wv.at(i+1).first) + wv.at(i+1).second;
            dp.at(i+1).at(j) = max(dp.at(i+1).at(j), value);
        }
    }
    
    cout << dp.at(N).at(W) << endl;
}