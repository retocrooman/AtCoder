#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i=0; i<(ll)(n); i++)
#define rev_rep(i, n) for (ll i=(n); i > 0; i--)
#define REP(i, n) for (ll i=1; i<=(ll)(n); i++)
#define FOR(i, n, m) for (ll i=(n); i<=(ll)(m); i++)
#define rev_FOR(i, n, m) for (ll i=(n); i<=(ll)(m); i--)
#define ll long long
#define vc vector<ll>
#define vc2 vector<vector<ll>>
#define vc3 vector<vector<vector<ll>>>
#define vcd vector<double>
#define vc2d vector<vector<double>>
#define vc3d vector<vector<vector<double>>>
#define vcs vector<string>
#define vc2s vector<vector<string>>
#define vc3s vector<vector<vector<string>>>
#define ALL(vec) vec.begin(),vec.end()
const ll INF=1LL<<60;
const ll mod = 1000000007;
const double pi=3.1415926535;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T>bool ch_max(T &a, const T &b) {if (a<b) {a = b; return 1; } return 0;}
template<class T>bool ch_min(T &a, const T &b) {if (b<a) {a = b; return 1; } return 0;}

int main() {
    ll N;
    cin >> N;
    vc A(N);
    rep(i, N) cin >> A.at(i);

    vc dp1(N+1), dp2(N+1);
    dp1.at(0) = 1;
    dp2.at(0) = 1;
    dp1.at(1) = 2;
    dp2.at(1) = 1;
    REP(i, N-2) {
        dp1.at(i+1) = dp1.at(i) + dp2.at(i);
        dp2.at(i+1) = dp1.at(i);
        dp1.at(i+1) %= mod;
        dp2.at(i+1) %= mod;
    }
    ll ans = A.at(0) * dp1.at(N-1) % mod;
    REP(i, N-1) {
        ll plus = 0;
        ll minus = 0;
        plus = dp1.at(i-1) * dp1.at(N-1-i) % mod; 
        minus = dp2.at(i-1) * dp2.at(N-1-i) % mod;
        ll sum = plus - minus;
        if (sum < 0) sum += mod;
        ans += A.at(i) * sum % mod;
        ans %= mod;
    }

    cout << ans << endl;
}