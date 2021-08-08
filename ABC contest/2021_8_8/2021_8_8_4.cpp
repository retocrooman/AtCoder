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

vc used(1000000);
vc2 AB(1000000);
vc ans;
unordered_map<ll, ll> mp;
unordered_map<ll, ll> mpAB;

void f(ll pos) {
    used.at(pos) = 1;
    ans.push_back(pos);
    ll next = 0;
    if(mpAB[pos] < AB.at(pos).size()) {
        if(AB.at(pos).at(mpAB[pos]) == mp[pos]) mpAB[pos]++;
        if(mpAB[pos] < AB.at(pos).size()) {
            next = AB.at(pos).at(mpAB[pos]);
            mpAB[pos]++;
        }
    }
    if(next == 0) {
        if(pos == 1) return;
        else f(mp[pos]);
    }
    else {
        mp[next] = pos;
        f(next);
    }
}

int main() {
    ll N;
    cin >> N;
    rep(i, N-1) {
        ll a,b;
        cin >> a >> b;
        AB.at(a).push_back(b);
        AB.at(b).push_back(a);
    }
    REP(i, N) {
        sort(AB.at(i).begin(), AB.at(i).end());
    }
    f(1);
    for(ll a: ans) cout << a << " ";
    cout << endl;
}