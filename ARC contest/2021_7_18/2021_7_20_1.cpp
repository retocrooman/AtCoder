#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i=0; i<(ll)(n); i++)
#define rev_rep(i, n) for (ll i=(n); i > 0; i--)
#define REP(i, n) for (ll i=1; i<=(ll)(n); i++)
#define FOR(i, n, m) for (ll i=(n); i<=(ll)(m); i++)
#define rev_FOR(i, n, m) for (ll i=(n); i>=(ll)(m); i--)
#define ll long long
#define ull unsigned long long
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

unordered_map<ll, int> memo;

int solve(ll N) {
    if(N == 0) return 0;
    if(memo.count(N)) return memo[N];
    ll p = N/10;
    ll q = N%10;
    int res = 0;
    if(1 <= q && q <= 3 && solve(p) <= 1) res = 1;
    else if(2 <= q && q <= 6 && solve(p) <= 2) res = 2;
    else if(3 <= q && q <= 9 && solve(p) <= 3) res = 3;
    else if(4 <= q && q <= 9 && solve(p) <= 4) res = 4;
    else if(0 <= q && q <= 2 && solve(p-1) <= 4) res = 4;
    else res = 5;
    memo[N] = res;
    return res;
}

int main() {
    ull T,N;
    cin >> T;
    rep(i, T) {
        cin >> N;
        cout << solve(N) << endl;
    }
}