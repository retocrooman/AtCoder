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
    vector<vector<int>> A(N+1, vector<int>(N+1));
    REP(i, N) {
        REP(j, N) {
            cin >> A.at(i).at(j);
        }
    }
    int M;
    cin >> M;
    vector<vector<int>> XY(N+1);
    REP(i, M) {
        int a, b;
        cin >> a >> b;
        XY.at(a).push_back(b);
        XY.at(b).push_back(a);
    }

    vector<int> n;
    REP(i, N) {
        n.push_back(i);
    }
    
    int ans = 10001;
    do {
        bool can = true;
        rep(i, N-1) {
            for (int a : XY.at(n.at(i))) {
                if (n.at(i+1) == a) can = false;
            }
        }
        if (!can) continue;
        int cnt = 0;
        rep(i, N) {
            cnt +=  A.at(n.at(i)).at(i+1);
        }
        ans = min(ans, cnt);
    } while (next_permutation(n.begin(), n.end()));

    if (ans == 10001) ans = -1;
    cout << ans << endl;
}