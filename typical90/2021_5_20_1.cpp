#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;
const double pi=3.1415926535;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> used(1002, vector<int>(1002));
    rep(i,N) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        FOR(j,ly+1,ry) {
            used.at(j).at(lx+1)++;
            used.at(j).at(rx+1)--;
        }
    }
    rep(i,1001) {
        rep(j,1000) {
            used.at(i).at(j+1) += used.at(i).at(j);
        }
    }
    vector<int> cnt(N+1);
    REP(i,1000) {
        REP(j,1000) {
            cnt.at(used.at(i).at(j))++;
        }
    }
    REP(i,N) {
        cout << cnt.at(i) << endl;
    }
}