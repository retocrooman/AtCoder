#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i=0; i<(ll)(n); i++)
#define rev_rep(i, n) for (ll i=(n); i > 0; i--)
#define REP(i, n) for (ll i=1; i<=(ll)(n); i++)
#define FOR(i, n, m) for (ll i=(n); i<=(ll)(m); i++)
#define rev_FOR(i, n, m) for (ll i=(n); i>=(ll)(m); i--)
#define ll long long
#define ull unsigned long long
#define vc vector<ll>
#define vc2 vector<vector<ll>>
#define vc3 vector<vector<vector<ll>>>
#define vcd vector<double>
#define vc2d vector<vector<double>>
#define vc3d vector<vector<vector<double>>>
#define vcs vector<string>
#define vc2s vector<vector<string>>
#define vc3s vector<vector<vector<string>>>
#define ALL(vec) vec.begin(),vec.end()
const ll INF=1LL<<60;
const ll mod = 1000000007;
const ll MOD = 998244353;
const double pi=3.1415926535;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T>bool ch_max(T &a, const T &b) {if (a<b) {a = b; return 1; } return 0;}
template<class T>bool ch_min(T &a, const T &b) {if (b<a) {a = b; return 1; } return 0;}

int main() {
    int N;
    cin >> N;
    int x4 = N%10;
    N /= 10;
    int x3 = N%10;
    N /= 10;
    int x2 = N%10;
    N /= 10;
    int x1 = N%10;
    bool weak = false;
    bool weak1 = false;
    bool weak2 = false;
    bool weak3 = false;
    if(x1 == x2 && x1 == x3 && x1 == x4) weak = true;
    if(x2-x1 == 1) weak1 = true;
    if(x3-x2 == 1) weak2 = true;
    if(x4-x3 == 1) weak3 = true;
    if(x2-x1 == -9) weak1 = true;
    if(x3-x2 == -9) weak2 = true;
    if(x4-x3 == -9) weak3 = true;
    if(weak1 && weak2 && weak3) weak = true;
    if(weak) cout << "Weak" << endl;
    else cout << "Strong" << endl;
}