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

int main() {
    ll N;
    cin >> N;
    vc A(N),B(N),C(N);
    rep(i, N) cin >> A.at(i);
    rep(i, N) cin >> B.at(i);
    rep(i, N) cin >> C.at(i);
    sort(ALL(A));
    sort(ALL(B));
    sort(ALL(C));
    ll posA = 0;
    ll posC = 0;
    ll ans = 0;
    rep(i, N) {
        bool ok = true;
        bool fin = false;
        if(B.at(i) <= A.at(posA)) ok = false;
        while(B.at(i) >= C.at(posC)) {
            posC++;
            if(posC == N) {
                fin = true;
                break;
            }
        }
        if(fin) break;
        if(ok) {
            ans++;
            posA++;
            posC++;
        }
        if(posA >= N) break;
        if(posC >= N) break;
    }
    cout << ans << endl;
}