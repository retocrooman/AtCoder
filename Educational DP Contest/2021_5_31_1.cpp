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
template<class T>bool ch_max(T &a, const T &b) {if (a<b) {a = b; return 1; } return 0}
template<class T>bool ch_min(T &a, const T &b) {if (b<a) {a = b; return 1; } return 0}

int N;
vc3d flag(301, vc2d(301, vcd(301)));
vc3d dp(301, vc2d(301, vcd(301)));

double f(int c1, int c2, int c3) {
    if(flag.at(c1).at(c2).at(c3)) return dp.at(c1).at(c2).at(c3);
    flag.at(c1).at(c2).at(c3) = 1;
    double a = 1-(double)(N-c1-c2-c3)/N;
    double fans = 1 / a;
    if(c1 > 0) fans += f(c1-1, c2, c3) * c1 / N / a;
    if(c2 > 0) fans += f(c1+1, c2-1, c3) * c2 / N / a;
    if(c3 > 0) fans += f(c1, c2+1, c3-1) * c3 / N / a;
    dp.at(c1).at(c2).at(c3) = fans;
    return fans;
}
int main() {
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    rep(i, N) {
        if (A.at(i) == 1) c1++;
        if (A.at(i) == 2) c2++;
        if (A.at(i) == 3) c3++;
    }
    flag.at(0).at(0).at(0) = 1;
    dp.at(0).at(0).at(0) = 0;
    double ans = f(c1, c2, c3);

    cout<< fixed << setprecision(10) << ans << endl;
}