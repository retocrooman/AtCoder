#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;
const double pi=3.1415926535;
const ll mod=1000000007;

int main() {
    int K;
    cin >> K;

    if (K % 9 != 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<ll> dp(100001);
    dp.at(0) = 1;
    REP(i, K) {
        int a = min(i, 9);
        REP(j, a) dp.at(i) += dp.at(i-j);
        dp.at(i) %= mod;
    }

    cout << dp.at(K) << endl;
}