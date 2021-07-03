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

int main() {
    int N,D;
    cin >> N >> D;
    vc A(N);
    rep(i, N) cin >> A.at(i);
    ll ans = 0;
    rep(i, (1<<N)) {
        ll bit = 0;
        int conditions = 0;
        rep(j, N) {
            if((i >> j) & 1) {
                bit |= A.at(j);
                conditions++;
            }
        }
        int free_digits = 0;
        rep(j, D) {
            if(((bit >> j) & 1) == 0) {
                free_digits++;
            }
        }
        if(conditions % 2 == 0) {
            ans += (1LL << free_digits);
        }
        else {
            ans -= (1LL << free_digits);
        }
    }
    cout << ans << endl;
}