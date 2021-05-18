#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;
const double pi=3.1415926535;

int N, cnt=0;
vector<vector<int>> AB(100001), color(100001, vector<int>(2));

void dfs(int pos, int col) {
    color.at(pos).at(1) = col;
    if (col == 1) {
        col = -1;
        cnt++;
    } else {
        col = 1;
    }
    for (int pre_pos : AB.at(pos)) {
        if (color.at(pre_pos).at(1) == 0) dfs(pre_pos, col);
    }
}

int main() {
    cin >> N;
    rep(i,N) {
        int a,b;
        cin >> a >> b;
        AB.at(a).push_back(b);
        AB.at(b).push_back(a);
    }
    REP(i,N) {
        color.at(i).at(0) = i;
    }
    dfs(1,1);
    int col=0;
    cnt >= N/2 ? col = 1 : col = -1;
    int ans_length = 0;
    REP(i,N) {
        if (color.at(i).at(1) == col) {
            cout << color.at(i).at(0) << " " << endl;
            ans_length++;
        }
        if (ans_length == N/2) {
            cout << endl;
            break;
        }
    }
}