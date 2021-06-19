#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i=0; i<(ll)(n); i++)
#define rev_rep(i, n) for (ll i=(n); i > 0; i--)
#define REP(i, n) for (ll i=1; i<=(ll)(n); i++)
#define FOR(i, n, m) for (ll i=(n); i<=(ll)(m); i++)
#define rev_FOR(i, n, m) for (ll i=(n); i<=(ll)(m); i--)
#define ll long long
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
    int N;
    cin >> N;
    vc A(200001);
    rep(i, N) cin >> A.at(i);
    set<ll> a;
    vc2 tree(200001);
    rep(i, N+1/2) {
        if(A.at(i) != A.at(N-i-1)) {
            a.insert(A.at(i));
            a.insert(A.at(N-i-1));
            tree.at(A.at(i)).push_back(A.at(N-i-1));
            tree.at(A.at(N-i-1)).push_back(A.at(N));
        }
    }
    ll group = 0;
    vc use(200001);
    rep(i, 200001) {
        if(tree.at(i).empty()) continue;
        if(use.at(i) == 1) continue;
        group++;
        queue<ll> que;
        que.push(i);
        while(!que.empty()) {
            ll q = que.front();
            que.pop();
            for(ll a : tree.at(q)) {
                if(use.at(a) == 1) continue;
                use.at(a) = 1;
                que.push(a);
            }
        }
    }
    if (a.size() == 0) cout << 0 << endl;
    else cout << a.size()-group << endl;
}