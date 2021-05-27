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
    int N;
    cin >> N;
    vector<int> a(N+1), b(N+1), c(N+1);
    REP(i, N) cin >> a.at(i) >> b.at(i) >> c.at(i);

    vector<vector<ll>> dp(N+1, vector<ll>(3));
    dp.at(1).at(0) = a.at(0);
    dp.at(1).at(1) = b.at(0);
    dp.at(1).at(2) = c.at(0);
    rep(i, N) {
        ll preA = max(dp.at(i).at(1), dp.at(i).at(2)) + a.at(i+1);
        ll preB = max(dp.at(i).at(0), dp.at(i).at(2)) + b.at(i+1);
        ll preC = max(dp.at(i).at(0), dp.at(i).at(1)) + c.at(i+1);
        dp.at(i+1).at(0) = preA;
        dp.at(i+1).at(1) = preB;
        dp.at(i+1).at(2) = preC;
    }

    ll ans = 0;
    rep(i, 3) ans = max(ans, dp.at(N).at(i));
    cout<< ans << endl;
}