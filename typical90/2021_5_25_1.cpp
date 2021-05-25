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
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    vector<vector<int>> T(Q+1, vector<int>(3));
    REP(i, Q) {
        rep(j, 3) cin >> T.at(i).at(j);
    }
    int cnt = 0;
    int diff = 0;
    REP(i, Q) {
        if (T.at(i).at(0) == 1) {
            int a = (T.at(i).at(1) + diff) % N;
            int b = (T.at(i).at(2) + diff) % N;
            a == 0 ? a = N-1 : a--;
            b == 0 ? b = N-1 : b--;
            ll c = A.at(a);
            ll d = A.at(b);
            A.at(a) = d;
            A.at(b) = c;
        }
        if (T.at(i).at(0) == 2) {
            cnt++;
            diff = N - cnt;
            if (diff == 0) cnt = 0;
        }
        if (T.at(i).at(0) == 3) {
            int a = (T.at(i).at(1) + diff) % N;
            a == 0 ? a = N-1 : a--;
            cout << A.at(a) << endl;
        }
    }
}
