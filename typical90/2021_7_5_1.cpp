#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i=0; i<(ll)(n); i++)
#define rev_rep(i, n) for (ll i=(n); i > 0; i--)
#define REP(i, n) for (ll i=1; i<=(ll)(n); i++)
#define FOR(i, n, m) for (ll i=(n); i<=(ll)(m); i++)
#define rev_FOR(i, n, m) for (ll i=(n); i>=(ll)(m); i--)
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
    ll N,K;
    cin >> N >> K;
    K++;
    vc2 in(5001, vc(5001));
    rep(i, N) {
        ll a,b;
        cin >> a >> b;
        in.at(a).at(b)++;
    }
    vc2 dp(5001, vc(5001));
    rep(i, 5000) {
        rep(j, 5000) {
            dp.at(i+1).at(j+1) = dp.at(i+1).at(j) + dp.at(i).at(j+1) - dp.at(i).at(j) + in.at(i+1).at(j+1);
        }
    }
    ll ans = 0;
    rep(i, 5001-K) {
        rep(j, 5001-K) {
            ans = max(ans, dp.at(i+K).at(j+K) - dp.at(i).at(j+K) - dp.at(i+K).at(j) + dp.at(i).at(j));
        }
    }
    cout << ans << endl;
}