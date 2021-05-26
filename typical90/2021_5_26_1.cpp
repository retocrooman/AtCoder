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
    int N,L;
    cin >> N >> L;

    vector<ll> dp(N+1);
    rep(i, N+1) dp.at(i) = 1;
    FOR(i, L, N) {
        dp.at(i) = dp.at(i-1) + dp.at(i-L);
        dp.at(i) %= mod;
    }

    cout<< dp.at(N) << endl;
}