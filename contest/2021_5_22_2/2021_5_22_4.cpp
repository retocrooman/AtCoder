#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;
const double pi=3.1415926535;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    rep(i, N) cin >> A.at(i);
    rep(i, N) cin >> B.at(i);
    rep(i, N) cin >> C.at(i);
    
    vector<int> Ab(N), Bc(N);
    rep(i, N) {
        Bc.at(B.at(C.at(i)-1)-1)++;
    }
    ll ans = 0;
    rep(i, N) {
        ans += Bc.at(A.at(i)-1);
    }
    cout << ans << endl;
}