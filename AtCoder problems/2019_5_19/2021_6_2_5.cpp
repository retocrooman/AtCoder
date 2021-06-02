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

vc2 xy(100001);
vc use(100001);
int cnt = 0;

void bfs(int a) {
    if (use.at(a) == 1) return;
    use.at(a) = 1;
    for (int b : xy.at(a)) bfs(b);
}
int main() {
    int N,M;
    cin >> N >> M;
    rep(i, M) {
        int x,y,z;
        cin >> x >> y >> z;
        xy.at(x).pb(y);
        xy.at(y).pb(x);
    }

    REP(i, N) {
        if (use.at(i) == 1) continue;
        cnt++;
        bfs(i);
    }

    cout << cnt << endl;
}