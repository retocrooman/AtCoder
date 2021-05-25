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
    int N,K;
    cin >> N >> K;
    vector<ll> A(N),B(N);
    rep(i, N) cin >> A.at(i) >> B.at(i);

    vector<ll> ans_vec(2*N);
    rep(i, N) ans_vec.at(i) = B.at(i);
    rep(i, N) ans_vec.at(N+i) = A.at(i) - B.at(i);
    sort(ans_vec.begin(), ans_vec.end());

    ll ans = 0;
    rep(i, K) {
        ans += ans_vec.back();
        ans_vec.pop_back();
    }

    cout << ans << endl;
}