#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;
const double pi=3.1415926535;

int N,M;
vector<bool> used(200001);
vector<vector<int>> A(200001),B(200001);
vector<int> I;
ll cnt=0;

void dfs(int pos) {
    used.at(pos) = true;
    for (auto i : A.at(pos)) {
        if (used.at(i) == false) dfs(i);
    }
    I.push_back(pos);
}

void dfs2(int pos) {
    used.at(pos) = true;
    cnt++;
    for (auto i : B.at(pos)) {
        if (used.at(i) == false) dfs2(i);
    }
}
int main() {
    cin >> N >> M;
    rep(i,M) {
        int a,b;
        cin >> a >> b;
        A.at(a).push_back(b);
        B.at(b).push_back(a);
    }
    REP(i,N) {
        if (used.at(i) == false) dfs(i);
    }
    ll ans=0;
    reverse(I.begin(), I.end());
    REP(i,N) used.at(i) = false;
    for (auto i : I) {
        if (used.at(i) == true) continue;
        cnt = 0;
        dfs2(i);
        ans += cnt * (cnt-1) / 2;
    }
    cout << ans << endl;
}