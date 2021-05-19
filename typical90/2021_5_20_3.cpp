#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;
const double pi=3.1415926535;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> cnt(N+1);
    FOR(i, 2, N) {
        if (cnt.at(i) != 0) continue;
        for (int j = i; j <= N; j += i) cnt.at(j)++;
    }
    int ans = 0;
    REP(i, N) {
        if (cnt.at(i) >= K) ans++;
    }
    cout << ans << endl;
}