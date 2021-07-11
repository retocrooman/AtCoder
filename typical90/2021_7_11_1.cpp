#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i=0; i<(ll)(n); i++)
#define rev_rep(i, n) for (ll i=(n); i > 0; i--)
#define REP(i, n) for (ll i=1; i<=(ll)(n); i++)
#define FOR(i, n, m) for (ll i=(n); i<=(ll)(m); i++)
#define rev_FOR(i, n, m) for (ll i=(n); i>=(ll)(m); i--)
#define ll long long
#define ull unsigned long long
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

ll N,Q;
vc X(100),Y(100),Z(100),W(100);
vc x(100),y(100),z(100),w(100);

ll b() {
    ll ways = 0;
    rep(i, 1<<N) {
        vc bit(13);
        rep(j, N) bit.at(j+1) = (i/(1<<j))%2;
        bool ok = true;
        REP(j, Q) {
            if(((bit.at(x.at(j)) | bit.at(y.at(j))) | bit.at(z.at(j))) != w.at(j)) ok = false;
        }
        if(ok) ways++;
    }
    return ways;
}

int main() {
    cin >> N >> Q;
    REP(i, Q) cin >> X.at(i) >> Y.at(i) >> Z.at(i) >> W.at(i);
    ll ans = 1;
    rep(i, 60) {
        REP(j, Q) {
            x.at(j) = X.at(j);
            y.at(j) = Y.at(j);
            z.at(j) = Z.at(j);
            w.at(j) = (W.at(j)/(1ll<<i))%2ll;
        }
        ll ret = b();
        ans *= ret;
        ans %= mod;
    }
    cout << ans << endl;
}