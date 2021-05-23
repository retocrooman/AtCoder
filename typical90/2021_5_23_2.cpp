#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;
const double pi=3.1415926535;

vector<vector<int>> ab(100001);
vector<int> par_count(100001);
int cnt = 0;

void dfs(int n, int m) {
    par_count.at(n) = 1;
    for (int a : ab.at(n)) {
        if (a != m) {
            dfs(a, n);
            par_count.at(n) += par_count.at(a);
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N+1), B(N+1);
    REP(i, N-1) {
        int a, b;
        cin >> a >> b;
        A.at(i) = a;
        B.at(i) = b;
        ab.at(a).push_back(b);
        ab.at(b).push_back(a);
    }

    dfs(1, -1);

    ll ans = 0;
    REP(i, N-1) {
        ll r = min(par_count.at(A.at(i)), par_count.at(B.at(i)));
        ans += (N - r) * r;
    }
    cout << ans << endl;
}