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
    int N, K;
    cin >> N >> K;
    vc V(N);
    rep(i, N) {
        cin >> V.at(i);
    }

    ll ans = 0;
    rep(L, N+1) {
        rep(R, N+1-L) {
            int rest = K - L - R;
            if (rest < 0) continue;
            vc has;
            rep(i, L) has.push_back(V.at(i));
            rep(i, R) has.push_back(V.at(N-1-i));
            sort(ALL(has));
            int n = has.size();
            ll sum = 0;
            for(int a : has) sum += a;
            rep(i, min(rest, n)) {
                if(0 < has.at(i)) break;
                sum -= has.at(i);
            }
            ch_max(ans, sum);
        }
    }

    cout << ans << endl;
}