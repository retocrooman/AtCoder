#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;
const double pi=3.1415926535;

class RangeMax{
    public:
    ll size_ = 1;
    vector<ll> dat;

    void init(int sz) {
        while (size_ <= sz) size_ *= 2;
        dat.resize(size_*2, -INF);
    }

    void update(ll pos, ll x) {
        pos += size_;
        dat.at(pos) = x;
        while (pos >= 2) {
            pos >>= 1;
            dat.at(pos) = max(dat.at(pos*2), dat.at(pos*2+1));
        }
    }

    ll query_(ll l, ll r, ll a, ll b, ll u) {
        if (l <= a && b <= r) return dat.at(u);
        if (r <= a || b <= l) return -INF;
        ll v1 = query_(l, r, a, (a+b) >> 1, u*2);
        ll v2 = query_(l, r, (a+b) >> 1, b, u*2 + 1);
        return max(v1, v2);
    }

    ll query(ll l, ll r) {
        return query_(l, r, 0, size_, 1);
    }
};

vector<RangeMax> Z(501);

int main () {
    int W, N;
    cin >> W >> N;
    vector<vector<int>> lr(N+1, vector<int>(2));
    vector<ll> v(N+1);
    REP(i, N) cin >> lr.at(i).at(0) >> lr.at(i).at(1) >> v.at(i);

    vector<vector<ll>> dp(N+1, vector<ll>(W+1));

    rep(i, N+1) {
        rep(j, W+1) {
            dp.at(i).at(j) = -INF;
        }
        Z.at(i).init(W + 1);
    }
    Z.at(0).update(0, 0);
    dp.at(0).at(0) = 0;

    REP(i, N) {
        rep(j, W+1) dp.at(i).at(j) = dp.at(i-1).at(j);
        rep(j, W+1) {
            ll cl = max(0, j - lr.at(i).at(1));
            ll cr = max(0, j - lr.at(i).at(0) + 1);
            if (cl == cr) continue;
            ll val = Z.at(i-1).query(cl, cr);
            if (val != -INF) dp.at(i).at(j) = max(dp.at(i).at(j), val + v.at(i));
        }
        rep(j, W+1) Z.at(i).update(j, dp.at(i).at(j));
    }
    if (dp.at(N).at(W) == -INF) cout << -1 << endl;
    else cout << dp.at(N).at(W) << endl;
}