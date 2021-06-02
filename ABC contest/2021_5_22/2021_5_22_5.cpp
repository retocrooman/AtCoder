#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;
const double pi=3.1415926535;

int main() {
    ll A,B,K;
    cin >> A >> B >> K;
    vector<vector<ll>> dp(A+1, vector<ll>(B+1));
    dp.at(0).at(0) = 1;
    rep(i, A+1) {
        rep(j, B+1){
            if (i > 0) dp.at(i).at(j) += dp.at(i-1).at(j);
            if (j > 0) dp.at(i).at(j) += dp.at(i).at(j-1);
        }
    }
    while (A > 0 && B > 0) {
        if (K <= dp.at(A-1).at(B)) {
            cout << 'a';
            A--;
        } else {
            K -= dp.at(A-1).at(B);
            cout << 'b';
            B--;
        }
    }
    cout << string(A, 'a');
    cout << string(B, 'b');
    cout << endl;
}