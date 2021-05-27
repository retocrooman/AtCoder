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

int main() {
    string s,t;
    cin >> s >> t;

    vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1));
    rep(i, s.size()) {
        rep(j, t.size()) {
            dp.at(i+1).at(j+1) = max(dp.at(i).at(j+1), dp.at(i+1).at(j));
            if (s.at(i) == t.at(j)) dp.at(i+1).at(j+1) = max(dp.at(i+1).at(j+1), dp.at(i).at(j) + 1);
        }
    }

    int a = dp.at(s.size()).at(t.size());
    int b = s.size();
    int c = t.size();
    string ans = "";
    while(a > 0) {
        if (s.at(b-1) == t.at(c-1)) {
            ans = t.at(c-1) + ans;
            a--;
            b--;
            c--;
        } else if (dp.at(b).at(c) == dp.at(b-1).at(c)) {
            b--;
        } else {
            c--;
        }
    }
    cout << ans << endl;
}