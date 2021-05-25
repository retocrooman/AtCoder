#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;
const ll mod = 1000000007;
const double pi=3.1415926535;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    ll N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    rep(i, N) cin >> A.at(i);
    rep(i, N) cin >> B.at(i);
    rep(i, N) cin >> C.at(i);

    rep(i, N) {
        A.at(i) %= 46;
        B.at(i) %= 46;
        C.at(i) %= 46;
    }
    vector<ll> a(46),b(46),c(46);
    rep(i, N){
        a.at(A.at(i))++;
        b.at(B.at(i))++;
        c.at(C.at(i))++;
    }
    ll ans = 0;
    rep(i, 46) {
        rep(j, 46) {
            rep(k, 46) {
                if ((i + j + k) % 46 == 0) ans += a.at(i) * b.at(j) * c.at(k);
            }
        }
    }

    cout<< ans << endl;
}