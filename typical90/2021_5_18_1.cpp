#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;
const double pi=3.1415926535;

int main() {
    ll N,K;
    cin >> N >> K;
    vector<int> A(N+1), B(N+1);
    REP(i,N) cin >> A.at(i);
    REP(i,N) cin >> B.at(i);
    vector<int> AB(N+1);
    REP(i,N) AB.at(i) = abs(A.at(i) - B.at(i));
    ll sum = 0;
    REP(i,N) sum += AB.at(i);
    if (K>=sum && (K-sum)%2 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}