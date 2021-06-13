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
    int N, M;
    cin >> N >> M;
    int k;
    vc2 s(M);
    rep(i, M) {
        cin >> k;
        int a;
        rep(j, k) {
            cin >> a;
            s.at(i).push_back(a);
        }
    }
    vc p(M);
    rep(i, M) cin >> p.at(i);

    vc on(N);
    int ans = 0;
    rep(i, (1<<N)) {
        rep(j, N) on.at(j) = 0;
        rep(j, N) {
            if ((i & (1<<j)) != 0) on.at(j) = 1;
        }
        bool can = true;
        rep(j, M) {
            int cnt = 0;
            for(int a : s.at(j)) {
                if (on.at(a-1) == 1) cnt++;
            }
            if (cnt%2 != p.at(j)) can = false;
        }
        if (can) ans++;
    }
    
    cout << ans << endl;
}