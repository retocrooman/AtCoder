#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define rev_rep(i, n) for (int i=(n); i > 0; i--)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define rev_FOR(i, n, m) for (int i=(n); i<=(int)(m); i--)
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
    int H,W;
    cin >> H >> W;
    vc2 P(H+1, vc(W+1));
    REP(i, H) {
        REP(j, W) cin >> P.at(i).at(j);
    }

    ll ans = 0;
    REP(i, (1<<H)-1) {
        //cout << i << " ";
        vc R;
        REP(j, W) {
            int index = -1;
            bool flag = false;
            rep(k, H) {
                if((i & (1<<k)) == 0) continue;
                //cout << P.at(k+1).at(j) << " ";
                if(index == -1) index = P.at(k+1).at(j);
                else if(index != P.at(k+1).at(j)) flag = true;
            }
            if(flag == false) R.push_back(index);
        }
        //cout << R.size() << endl;
        ll cntH = 0;
        ll cntW = 0;
        map<ll, ll> Map;
        for(ll a : R) {
            Map[a] += 1;
            cntW = max(cntW, Map[a]);
        }
        rep(j, H) {
            if((i & (1<<j)) != 0) cntH++;
        }
        ans = max(ans, cntH*cntW);
    }

    cout << ans << endl;
}