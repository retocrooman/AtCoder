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
#define vcl vector<ll>
#define vc2l vector<vector<ll>>
#define vc3l vector<vector<vector<ll>>>
#define vcd vector<double>
#define vc2d vector<vector<double>>
#define vc3d vector<vector<vector<double>>>
#define vcs vector<string>
#define vc2s vector<vector<string>>
#define vc3s vector<vector<vector<string>>>
#define ALL(vec) vec.begin(),vec.end()
#define SIZE(vec) vec.size()
#define pb push_back
#define greater greater<>()
const ll INF=1LL<<60;
const ll mod = 1000000007;
const double pi=3.1415926535;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T>bool ch_max(T &a, const T &b) {if (a<b) {a = b; return 1; } return 0;}
template<class T>bool ch_min(T &a, const T &b) {if (b<a) {a = b; return 1; } return 0;}

int main() {
    ll N,M;
    cin >> N >> M;
    vc2 AB(N);
    rep(i, M) {
        int a,b;
        cin >> a >> b;
        AB.at(a-1).pb(b-1);
    }
    
    ll sum = 0;
    rep(i, N) {
        queue<int> que;
        que.push(i);
        vc use(N);
        rep(j, N) use.at(j) = 0;
        use.at(i) = 1;
        while(!que.empty()) {
            int a = que.front();
            que.pop();
            sum++;
            for(int b : AB.at(a)) {
                if (use.at(b) == 1) continue;
                use.at(b) = 1;
                //cout << "a " << i << " b " << b << " ";
                que.push(b);
            }
        }
    }

    cout << sum << endl;
}