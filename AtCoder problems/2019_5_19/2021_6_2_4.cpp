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
#define ALL(vec) vec.begin(),vec.end()
#define SIZE(vec) vec.size()
#define pb push_back
const ll INF=1LL<<60;
const ll mod = 1000000007;
const double pi=3.1415926535;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T>bool ch_max(T &a, const T &b) {if (a<b) {a = b; return 1; } return 0;}
template<class T>bool ch_min(T &a, const T &b) {if (b<a) {a = b; return 1; } return 0;}

int N;
vc2l odd(100001), even(100001);
vc color(100001, -1);
void bfs(int a, int b) {
    if (color.at(a) != -1) return;
    if (b) {
        color.at(a) = 0;
        for(int c : odd.at(a)) bfs(c, 0);
        for(int c : even.at(a)) bfs(c, 1);
    } else {
        color.at(a) = 1;
        for(int c : odd.at(a)) bfs(c, 1); 
        for(int c : even.at(a)) bfs(c, 0); 
    }
}

int main() {
    cin >> N;
    rep(i, N-1) {
        int v1,v2;
        ll w;
        cin >> v1 >> v2 >> w;
        if (w%2 == 1) {
            odd.at(v1).pb(v2);
            odd.at(v2).pb(v1);
        } else {
            even.at(v1).pb(v2);
            even.at(v2).pb(v1);
        }
    }

    bfs(1, 0);

    REP(i, N) cout << color.at(i) << endl;
}