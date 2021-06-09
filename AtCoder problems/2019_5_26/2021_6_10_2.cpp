#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define rev_rep(i, n) for (int i=(n); i > 0; i--)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define rev_FOR(i, n, m) for (int i=(n); i<=(int)(m); i--)
#define ll long long
#define vc vector<ll>
#define vc2 vector<vector<ll>>
#define vc3 vector<vector<vector<ll>>>
#define vcd vector<double>
#define vc2d vector<vector<double>>
#define vc3d vector<vector<vector<double>>>
#define vcs vector<string>
#define vc2s vector<vector<string>>
#define vc3s vector<vector<vector<string>>>
#define ALL(vec) vec.begin(),vec.end()
const ll INF=1LL<<60;
const ll mod = 1000000007;
const double pi=3.1415926535;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T>bool ch_max(T &a, const T &b) {if (a<b) {a = b; return 1; } return 0;}
template<class T>bool ch_min(T &a, const T &b) {if (b<a) {a = b; return 1; } return 0;}

int main() {
    int N;
    cin >> N;
    vector<pair<string, int>> si(N);
    vector<pair<int, int>> pi(N);
    rep(i, N) {
        cin >> si.at(i).first >> pi.at(i).first;
        si.at(i).second = i+1;
        pi.at(i).second = i+1;
    }
    sort(ALL(si));
    int point = 100000;
    rep(i, N) {
        if (si.at(0).second == pi.at(i).second) pi.at(i).first += point;
    }
    rep(i, N-1) {
        if (si.at(i).first == si.at(i+1).first) {
            rep(j, N) {
                if (si.at(i+1).second == pi.at(j).second) pi.at(j).first += point;
            }
        } else {
            point -= 1000;
            rep(j, N) {
                if (si.at(i+1).second == pi.at(j).second) pi.at(j).first += point;
            }
        }
    }
    sort(ALL(pi), greater<>());
    rep(i, N) cout << pi.at(i).second << endl;
}