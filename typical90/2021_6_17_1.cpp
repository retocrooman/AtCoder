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
    int N,Q;
    cin >> N >> Q;
    vc A(N);
    rep(i, N) cin >> A.at(i);
    vc L(Q),R(Q),V(Q);
    rep(i, Q) cin >> L.at(i) >> R.at(i) >> V.at(i);

    ll ans = 0;
    vc orient(N-1);
    REP(i, N-1) {
        ans += abs(A.at(i) - A.at(i-1));
        orient.at(i-1) = A.at(i) - A.at(i-1);
    }
    rep(i, Q) {
        if(L.at(i) != 1) {
            ll pre = orient.at(L.at(i)-2);
            orient.at(L.at(i)-2) += V.at(i);
            ans -= abs(pre);
            ans += abs(orient.at(L.at(i)-2));
        }
        if(R.at(i) != N) {
            ll pre = orient.at(R.at(i)-1);
            orient.at(R.at(i)-1) -= V.at(i);
            ans -= abs(pre);
            ans += abs(orient.at(R.at(i)-1));
        }
        //for(ll a : orient) cout << " " << a;
        //cout << endl;
        cout << ans << endl;
    }
}