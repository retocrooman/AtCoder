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

int main() {
    ll N,M;
    cin >> N >> M;
    vc A(M),B(M);
    rep(i, M) cin >> A.at(i) >> B.at(i);
    ll Q;
    cin >> Q;
    vc X(Q),Y(Q);
    rep(i, Q) cin >> X.at(i) >> Y.at(i);

    vc2 tree(N+1);
    rep(i, M) {
        tree.at(A.at(i)).push_back(B.at(i));
        tree.at(B.at(i)).push_back(A.at(i));
    }
    vc color(N+1, 1);
    rep(i, Q) {
        cout << color.at(X.at(i)) << endl;
        color.at(X.at(i)) = Y.at(i);
        for(ll a : tree.at(X.at(i))) color.at(a) = Y.at(i);
    }
}