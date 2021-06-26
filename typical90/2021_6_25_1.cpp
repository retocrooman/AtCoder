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

vc2 C(18, vc(18));
vc2 used(18, vc(18));

int dfs(int sx, int sy, int px, int py) {
    if(sx == px && sy == py && used.at(px).at(py) == 1) return 0;
    used.at(px).at(py) = 1;
    int ans = -1000;
    rep(i, 4) {
        int nx = px + dx[i];
        int ny = py + dy[i];
        if(C.at(nx).at(ny) == 0) continue;
        if((sx != nx || sy != ny) && used.at(nx).at(ny) == 1) continue;
        int v = dfs(sx, sy, nx, ny);
        ans = max(ans, v+1);
    }
    used.at(px).at(py) = 0;
    return ans;
}

int main() {
    int H,W;
    cin >> H >> W;
    REP(i, H) {
        REP(j, W) {
            char c;
            cin >> c; 
            if(c == '.') C.at(i).at(j) = 1;
        }
    }
    int ans = 0;
    REP(i, H) {
        REP(j, W) {
            if(C.at(i).at(j) == 0) continue;
            ans = max(ans, dfs(i, j, i, j);
        }
    }
    cout << (ans < 3 ? -1 : ans) << endl;
}