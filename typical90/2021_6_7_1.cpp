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
    ll N,K;
    cin >> N >> K;
    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }
    ll n = N;
    int key = 0;
    int cnt = 0;
    vc use(100100, -1);
    use.at(n) = 0;
    while(key == 0) {
        cnt++;
        int a = n/10000;
        int b = n/1000 - a*10;
        int c = n/100 - a*100 - b*10;
        int d = n/10 - a*1000 - b*100 - c*10;
        int e = n%10;
        n += a + b + c + d + e;
        n %= 100000;
        if (use.at(n) != -1) {
            key = cnt - use.at(n);
        }
        else use.at(n) = cnt;
    }
    if (K - use.at(n) >= 0) {
        K -= use.at(n);
        K %= key;
        K += use.at(n);
    }
    rep(i, 100000) {
        if (use.at(i) == K) N = i;
    }
    cout << N << endl;
}