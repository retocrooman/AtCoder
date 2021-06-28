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

vcs C(100010);
vc2 dp(100010, vc(3));
vc2 tree(100010);

void dfs(int pos, int pre) {
    ll val1 = 1;
    ll val2 = 1;
    for(ll a : tree.at(pos)) {
        if(a == pre) continue;
        dfs(a, pos);
        if(C.at(pos) == "a") {
            val1 *= dp.at(a).at(0) + dp.at(a).at(2);
            val2 *= dp.at(a).at(0) + dp.at(a).at(1) + (dp.at(a).at(2))*2ll;
        }
        if(C.at(pos) == "b") {
            val1 *= dp.at(a).at(1) + dp.at(a).at(2);
            val2 *= dp.at(a).at(0) + dp.at(a).at(1) + (dp.at(a).at(2))*2ll;
        }
        val1 %= mod;
        val2 %= mod;
    }
    if(C.at(pos) == "a") {
        dp.at(pos).at(0) = val1;
        dp.at(pos).at(2) = (val2 - val1 + mod) % mod;
    }
    if(C.at(pos) == "b") {
        dp.at(pos).at(1) = val1;
        dp.at(pos).at(2) = (val2 - val1 + mod) % mod;
    }
}

int main() {
    int N;
    cin >> N;
    REP(i, N) cin >> C.at(i);
    rep(i, N-1) {
        int a,b;
        cin >> a >> b;
        tree.at(a).push_back(b);
        tree.at(b).push_back(a);
    }

    dfs(1, -1);
    cout << dp.at(1).at(2) << endl;
}