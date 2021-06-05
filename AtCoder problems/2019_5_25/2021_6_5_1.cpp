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
#define vcs vector<string>
#define vc2s vector<vector<string>>
#define vc3s vector<vector<vector<string>>>
#define ALL(vec) vec.begin(),vec.end()
#define SIZE(vec) vec.size()
#define pb push_back
#define greater greater<>()
const ll INF=1LL<<60;
const ll mod = 1000000007;
const double pi=3.1415926535;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T>bool ch_max(T &a, const T &b) {if (a<b) {a = b; return 1; } return 0;}
template<class T>bool ch_min(T &a, const T &b) {if (b<a) {a = b; return 1; } return 0;}

int main() {
    int N,M;
    cin >> N >> M;
    vcl A(N);
    vc2l BC(M, vcl(2));
    rep(i, N) cin >> A.at(i);
    rep(i, M) cin >> BC.at(i).at(1) >> BC.at(i).at(0);

    sort(ALL(A));
    sort(ALL(BC), greater);
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    while(BC.at(cnt2).at(0) > A.at(cnt1)) {
        A.at(cnt1) = BC.at(cnt2).at(0);
        cnt1++;
        cnt3++;
        if(cnt3 == BC.at(cnt2).at(1)) {
            cnt2++;
            cnt3 = 0;
        }
        if(cnt1 >= N) break;
        if(cnt2 >= M) break;
    }
    ll ans = 0;
    rep(i, N) {
        ans += A.at(i);
    }

    cout << ans << endl;
}