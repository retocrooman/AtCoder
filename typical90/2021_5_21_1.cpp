#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;
const double pi=3.1415926535;


int main() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> x(N+1), y(N+1), q(Q);
    REP(i, N) cin >> x.at(i) >> y.at(i);
    rep(i, Q) cin >> q.at(i);

    REP(i, N) {
        int a = x.at(i);
        int b = y.at(i);
        x.at(i) = a - b;
        y.at(i) = a + b;
    }
    
    vector<ll> X, Y;
    REP(i, N) {
        X.push_back(x.at(i));
        Y.push_back(y.at(i));
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    ll right = X.back();
    ll left = X.front();
    ll top = Y.back();
    ll bottom = Y.front();

    for (int a : q) {
        ll ans = 0;
        ans = max(ans, abs(x.at(a) - right));
        ans = max(ans, abs(x.at(a) - left));
        ans = max(ans, abs(y.at(a) - top));
        ans = max(ans, abs(y.at(a) - bottom));
        cout << ans << endl;
    }
}