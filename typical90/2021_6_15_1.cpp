#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define rev_rep(i, n) for (int i=(n); i > 0; i--)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define rev_FOR(i, n, m) for (int i=(n); i<=(int)(m); i--)
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
    vc A(N+1),B(N+1);
    vc2 G(N+1);
    queue<ll> que;
    vc used(N+1);
    REP(i, N) {
        cin >> A.at(i) >> B.at(i);
        G.at(A.at(i)).push_back(i);
        G.at(B.at(i)).push_back(i);
        if(A.at(i) == i || B.at(i) == i) {
            used.at(i) = 1;
            que.push(i);
        }
    }

    vc ans;
    while(!que.empty()) {
        int pos = que.front();
        que.pop();
        ans.push_back(pos);
        for(ll a : G.at(pos)) {
            if(used.at(a) == 1) continue;
            used.at(a) = 1;
            que.push(a);
        }
    }

    reverse(ALL(ans));
    if (ans.size() != N) {
        cout << -1 << endl;
    }
    else {
        for(ll a : ans) cout << a << endl;
    }
}