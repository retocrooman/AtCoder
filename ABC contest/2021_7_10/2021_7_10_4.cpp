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
const double pi=3.1415926535;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T>bool ch_max(T &a, const T &b) {if (a<b) {a = b; return 1; } return 0;}
template<class T>bool ch_min(T &a, const T &b) {if (b<a) {a = b; return 1; } return 0;}

int main() {
    int N,Q;
    cin >> N >> Q;
    vc tree(N);
    vc odd(N);
    odd.at(0) = 1;
    vc2 ab(N);
    rep(i, N-1) {
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        ab.at(a).push_back(b);
        ab.at(b).push_back(a);
    }
    deque<ll> que;
    que.push_back(0);
    while(!que.empty()) {
        ll pos = que.front();
        que.pop_front();
        if(tree.at(pos) == 1) continue;
        tree.at(pos) = 1;
        for(ll a : ab.at(pos)) {
            if(tree.at(a) == 1) continue;
            odd.at(a) = 1-odd.at(pos);
            que.push_back(a);
        }
    }
    vc c(Q),d(Q);
    rep(i, Q) {
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        c.at(i) = a;
        d.at(i) = b;
    }
    rep(i, Q) {
        if(odd.at(c.at(i)) == odd.at(d.at(i))) cout << "Town" << endl;
        else cout << "Road" << endl;
    }
}