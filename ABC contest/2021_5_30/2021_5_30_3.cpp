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
    ll N,K;
    cin >> N >> K;
    vector<pair<ll,ll>> A(N+1);
    rep(i, N) cin >> A.at(i+1).first >> A.at(i+1).second;
    sort(A.begin(), A.end());
    rep(i, N) {
        if(K < A.at(i+1).first) {
            cout << K << endl;
            return 0;
        }
        K += A.at(i+1).second;
    }
    cout << K << endl;
}