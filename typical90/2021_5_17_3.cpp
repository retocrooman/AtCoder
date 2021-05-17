#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;
const double pi=3.1415926535;

ll gcd(ll x, ll y) {
    while (y > 0) {
        ll r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main() {
    ll a,b,c,cnt;
    cin >> a >> b >> c;
    cnt = gcd(a,gcd(b,c));
    a = a / cnt - 1ll;
    b = b / cnt - 1ll;
    c = c / cnt - 1ll;
    cout << a+b+c << endl;
}