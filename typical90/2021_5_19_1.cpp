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
    vector<pair<string, int>> used(N);
    vector<int> ans;
    rep(i,N) {
        cin >> used.at(i).first;
        used.at(i).second = i+1;
    }
    stable_sort(used.begin(), used.end());
    ans.push_back(used.front().second);
    rep(i,N-1) {
        if (used.at(i).first != used.at(i+1).first) {
            ans.push_back(used.at(i+1).second);
        }
    }
    sort(ans.begin(), ans.end());
    rep(i,ans.size()) {
        cout << ans.at(i) << endl;
    }
}