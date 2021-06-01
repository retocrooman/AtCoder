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

int main() {
    ll N, P, Q;
    cin >> N >> P >> Q;
    vcl A(N);
    rep(i, N) {
        cin >> A.at(i);
        A.at(i) %= P;
    }

    ll cnt = 0;
    rep(i, N) {
        ll sum1 = A.at(i);
        FOR(j, i+1, N-1) {
            ll sum2 = sum1 * A.at(j);
            sum2 %= P;
            FOR(k, j+1, N-1) {
                ll sum3 = sum2 * A.at(k);
                sum3 %= P;
                FOR(l, k+1, N-1) {
                    ll sum4 = sum3 * A.at(l);
                    sum4 %= P;
                    FOR(m, l+1, N-1) {
                        ll sum5 = sum4 * A.at(m);
                        if(sum5 % P == Q) cnt++;
                    }
                }
            }
        }
    }

    cout << cnt << endl;
}