#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;
const double pi=3.1415926535;

ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int main() {
    ll large = 1;
    rep(i, 18) large *= 10;
    ll A,B;
    cin >> A >> B;
    ll C = gcd(A, B);
    ll D = A / C * B;
    if (A / C <= large / B) cout << D << endl;
    else cout << "Large" << endl;
}