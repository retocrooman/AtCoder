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
    ll P;
    cin >> N >> K >> P;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);

    int mid = N/2;
    vector<vector<ll>> half1(N+1), half2(N+1);
    rep(i, 1<<mid) {
        ll sum = 0;
        int cnt = 0;
        rep(j, mid) {
            if((i&1<<j) != 0) {
                sum += A.at(j);
                cnt++;
            }
        }
        half1.at(cnt).push_back(sum);
        //cout << cnt << " " << sum << endl;
    }
    rep(i, 1<<(N-mid)) {
        ll sum = 0;
        int cnt = 0;
        rep(j, N-mid) {
            if((i&1<<j) != 0) {
                sum += A.at(mid + j);
                cnt++;
            }
        }
        half2.at(cnt).push_back(sum);
    }

    rep(i, N+1) {
        sort(half1.at(i).begin(), half1.at(i).end());
        sort(half2.at(i).begin(), half2.at(i).end());
    }
    ll ans = 0;
    rep(i, K+1) {
        for(ll a : half1.at(i)) {
            int pos = lower_bound(half2.at(K-i).begin(), half2.at(K-i).end(), P-a+1) - half2.at(K-i).begin();
            ans += pos;
            //cout << i << " " << P-a+1 << " " << ans << endl;
        }
    }

    cout << ans << endl;
}