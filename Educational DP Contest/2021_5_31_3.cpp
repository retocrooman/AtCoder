#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define rev_rep(i, n) for (int i=(n); i > 0; i--)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define rev_FOR(i, n, m) for (int i=(n); i<=(int)(m); i--)
#define ll long long
#define vc vector<int>
#define vc2 vector<vector<int>>
#define vc3 vector<vector<vector<int>>>
#define vcl vector<ll>
#define vc2l vector<vector<ll>>
#define vc3l vector<vector<vector<ll>>>
#define vcd vector<double>
#define vc2d vector<vector<double>>
#define vc3d vector<vector<vector<double>>>
#define ALL(vec) vec.begin(),vec.end()
#define SIZE(vec) vec.size()
#define pb push_back
const ll INF=1LL<<60;
const ll mod = 1000000007;
const double pi=3.1415926535;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T>bool ch_max(T &a, const T &b) {if (a<b) {a = b; return 1; } return 0;}
template<class T>bool ch_min(T &a, const T &b) {if (b<a) {a = b; return 1; } return 0;}

int N;
vcl a(3000);
vc2l dp(3000, vcl(3000)), flag(3000, vcl(3000));

ll f(int cl, int cr, int c) {
    if (cl == cr) return a.at(0);
    if (flag.at(cl).at(cr) == 1) return dp.at(cl).at(cr);
    flag.at(cl).at(cr) = 1;
    if (cr - cl == 1) {
        if (c) {
            dp.at(cl).at(cr) = abs(a.at(cl) - a.at(cr));
            return abs(a.at(cl) - a.at(cr));
        }
        else {
            dp.at(cl).at(cr) = -abs(a.at(cl) - a.at(cr));
            return -abs(a.at(cl) - a.at(cr));
        }
    }
    if (c) {
        dp.at(cl).at(cr) = max(f(cl+1, cr, 0) + a.at(cl), f(cl, cr-1, 0) + a.at(cr));
        return dp.at(cl).at(cr);
    }
    else {
        dp.at(cl).at(cr) = min(f(cl+1, cr, 1) - a.at(cl), f(cl, cr-1, 1) - a.at(cr));
        return dp.at(cl).at(cr);
    }
}

int main() {
    cin >> N;
    rep(i, N) cin >> a.at(i);

    ll ans = f(0, N-1, 1);
    /*rep(i, N) {
        FOR(j, i+1, N-1) cout << dp.at(i).at(j) << " ";
        cout << endl;
    }*/

    cout << ans << endl;
}