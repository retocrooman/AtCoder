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
    int N;
    cin >> N;
    vc t(N),l(N),r(N);
    rep(i, N) cin >> t.at(i) >> l.at(i) >> r.at(i);
    ll ans = 0;
    rep(i, N) {
        FOR(j, i+1, N-1) {
            if(r.at(i) < l.at(j)) continue;
            if(r.at(j) < l.at(i)) continue;
            if(r.at(i) == l.at(j) && t.at(i) == 2) continue;
            if(r.at(i) == l.at(j) && t.at(i) == 4) continue;
            if(r.at(i) == l.at(j) && t.at(j) == 4) continue;
            if(r.at(i) == l.at(j) && t.at(j) == 3) continue;
            if(r.at(j) == l.at(i) && t.at(i) == 3) continue;
            if(r.at(j) == l.at(i) && t.at(i) == 4) continue;
            if(r.at(j) == l.at(i) && t.at(j) == 4) continue;
            if(r.at(j) == l.at(i) && t.at(j) == 2) continue;
            ans++;
        }
    }
    cout << ans << endl;
}