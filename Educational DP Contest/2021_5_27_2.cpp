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
    int N,K;
    cin >> N >> K;
    K = min(N, K);
    vector<ll> h(N+1);
    REP(i, N) cin >> h.at(i);
    
    vector<ll> dp(N+1);
    REP(i, K) dp.at(i) = abs(h.at(i) - h.at(1));
    REP(i, N-K) {
        ll cost = INF;
        rep(j, K) cost = min(cost, dp.at(i+j) + abs(h.at(i+K) - h.at(i+j)));
        dp.at(i+K) = cost;
    }
    cout<< dp.at(N) << endl;
}