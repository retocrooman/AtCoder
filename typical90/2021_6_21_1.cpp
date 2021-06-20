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
    string S;
    ll K;
    cin >> S >> K;
    if(S == "0") {
        cout << 0 << endl;
        return 0;
    }
    vc idx(0);
    rev_rep(i, S.size()) {
        idx.push_back(S.at(i-1)-'0');
    }
    ll pre = 0;
    ll mlt = 1;
    for(ll a : idx) {
        pre += a * mlt;
        mlt *= 8;
    }
    rep(i, K) {
        vc ans(0);
        while(pre != 0) {
            ll a = pre%9;
            if(a == 8) a = 5;
            ans.push_back(a);
            pre /= 9;
        }
        mlt = 1;
        for(ll a : ans) {
            pre += a * mlt;
            mlt *= 8;
        }
        if(i != K-1) continue;
        rev_rep(j, ans.size()) {
            cout << ans.at(j-1);
        }
    }
    cout << endl;
}