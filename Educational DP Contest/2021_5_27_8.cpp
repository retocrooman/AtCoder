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
    vector<double> P(N+1);
    REP(i, N) cin >> P.at(i);

    vector<vector<double>> dp(N+1, vector<double>(N+1));
    dp.at(0).at(0) = 1;
    REP(i, N) dp.at(i).at(0) = dp.at(i-1).at(0) * P.at(i);
    REP(i, N) dp.at(0).at(i) = dp.at(0).at(i-1) * (1 - P.at(i));
    rep(i, N) {
        rep(j, N-i-1) {
            dp.at(i+1).at(j+1) = dp.at(i+1).at(j) * (1 - P.at(i+j+2)) + dp.at(i).at(j+1) * P.at(i+j+2);
        }
    }
    
    /*rep(i, N+1) {
        rep(j, N-i+1) {
            cout << dp.at(i).at(j) << " ";
        }
        cout << endl;
    }*/


    double ans = 0;
    rep(i, N+1) {
        if (i > N-i) ans += dp.at(i).at(N-i);
    }
    cout << fixed << setprecision(10) << ans << endl;
}