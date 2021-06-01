#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define rev_rep(i, n) for (int i=(n); i > 0; i--)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define rev_FOR(i, n, m) for (int i=(n); i<=(int)(m); i--)
#define ll long long
#define vc vector<int>
#define vc2 vector<vector<int>>
#define vc3 vector<vector<vector<int>>>
#define vcd vector<double>
#define vc2d vector<vector<double>>
#define vc3d vector<vector<vector<double>>>
#define ALL(vec) vec.begin(),vec.end()
#define SIZE(vec) vec.size()
#define pb push_back
const ll INF=1LL<<60;
const ll mod = 1000000007;
const double pi=3.1415926535;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T>bool ch_max(T &a, const T &b) {if (a<b) {a = b; return 1; } return 0}
template<class T>bool ch_min(T &a, const T &b) {if (b<a) {a = b; return 1; } return 0}

int main() {
    int N,M,K;
    cin >> N >> M;
    vc2 G(N+M);
    vc2 R(M);
    rep(i, M) {
        cin >> K;
        rep(j, K) {
            cin >> R.at(i).at(j);
            R.at(i).at(j)--;
            G.at(R.at(i).at(j)).pb(N+i);
            G.at(N+i).pb(R.at(i).at(j));
        }
    }

    queue<int> que;
    que.push(0);
    vector<int> dist(N+M, -2);
    dist.at(0) = 0;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for(int i : G.at(u)) {
            if(dist.at(i) == -2) {
                dist.at(i) = dist.at(u) + 1;
                que.push(i);
            }
        }
    }
    rep(i, N) {
        cout << dist.at(i) / 2 << endl;
    }
}