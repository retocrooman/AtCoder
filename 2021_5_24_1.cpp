#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;
const ll mod = 1000000007;
const double pi=3.1415926535;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct state {
    int x, y, dir;
};

int main() {
    int H,W;
    cin >> H >> W;
    int rs,cs,rt,ct;
    cin >> rs >> cs >> rt >> ct;
    vector<vector<char>> maze(H+1, vector<char>(W+1));
    REP(i, H) {
        REP (j, W) {
            cin >> maze.at(i).at(j);
        }
    }

    vector<vector<vector<ll>>> dp(H+1, vector<vector<ll>>(W+1, vector<ll>(4)));
    REP(i, H) {
        REP(j, W) {
            rep(k, 4) dp.at(i).at(j).at(k) = INF;
        }
    }

    deque<state> deq;
    rep(i, 4) {
        dp.at(rs).at(cs).at(i) = 0;
        deq.push_back({rs, cs, i});
    }

    while(!deq.empty()) {
        state u = deq.front();
        deq.pop_front();
        rep(i, 4) {
            int tx = u.x + dx[i];
            int ty = u.y + dy[i];
            int cost = dp.at(u.x).at(u.y).at(u.dir) + (u.dir == i ? 0 : 1);
            if (1 > tx || tx > H || 1 > ty || ty > W)  continue;
            if (maze.at(tx).at(ty) == '#') continue;
            if (dp.at(tx).at(ty).at(i) > cost) {
                dp.at(tx).at(ty).at(i) = cost;
                //cout << cost << " " << i << " " << tx << " " << ty << endl;
                if (u.dir == i) deq.push_front({tx, ty, i});
                else deq.push_back({tx, ty, i});
            }
        }
    }

    ll answer = INF; 
    rep(i, 4) answer = min(answer, dp.at(rt).at(ct).at(i));
    if (answer == INF) answer = 0;
    cout << answer << endl;
}