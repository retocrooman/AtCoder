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
    ll N,P,K;
    cin >> N >> P >> K;
    vc2 A(N, vc(N));
    rep(i, N) {
        rep(j, N) cin >> A.at(i).at(j);
    }
    ll left = 0;
    ll right = INF;
    vc2 dp(N, vc(N));
    ll sum = 0;
    while(right > left+1) {
        ll mid = (left+right)/2;
        rep(i, N) {
            rep(j, N) {
                dp.at(i).at(j) = A.at(i).at(j);
                if(dp.at(i).at(j) == -1) dp.at(i).at(j) = mid;
            }
        }
        rep(k, N) {
            rep(i, N) {
                rep(j, N) dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i).at(k)+dp.at(k).at(j));
            }
        }
        sum = 0;
        rep(i, N) {
            rep(j, N) {
                if(i >= j) continue;
                if(dp.at(i).at(j) <= P) sum++;
            }
        }
        if(sum < K) right = mid;
        if(sum >= K) left = mid;
    }
    ll R = left;
    left = 0;
    right = INF;
    while(right > left+1) {
        ll mid = (left+right)/2;
        rep(i, N) {
            rep(j, N) {
                dp.at(i).at(j) = A.at(i).at(j);
                if(dp.at(i).at(j) == -1) dp.at(i).at(j) = mid;
            }
        }
        rep(k, N) {
            rep(i, N) {
                rep(j, N) dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i).at(k)+dp.at(k).at(j));
            }
        }
        sum = 0;
        rep(i, N) {
            rep(j, N) {
                if(i >= j) continue;
                if(dp.at(i).at(j) <= P) sum++;
            }
        }
        if(sum <= K) right = mid;
        if(sum > K) left = mid;
    }
    ll L = left;
    //cout << R << " " << L << endl;
    if(R == INF-1 && L != INF-1) cout << "Infinity" << endl;
    else cout << max(0ll, R-L) << endl;
}