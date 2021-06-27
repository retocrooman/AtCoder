#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i=0; i<(ll)(n); i++)
#define rev_rep(i, n) for (ll i=(n); i > 0; i--)
#define REP(i, n) for (ll i=1; i<=(ll)(n); i++)
#define FOR(i, n, m) for (ll i=(n); i<=(ll)(m); i++)
#define rev_FOR(i, n, m) for (ll i=(n); i<=(ll)(m); i--)
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
const int ox[4] = {1, -1, 1, -1};
const int oy[4] = {1, 1, -1, -1};
template<class T>bool ch_max(T &a, const T &b) {if (a<b) {a = b; return 1; } return 0;}
template<class T>bool ch_min(T &a, const T &b) {if (b<a) {a = b; return 1; } return 0;}

int CrossProduct(vc &a, vc &b, vc &c) {
    return (a[0]-c[0])*(b[1]-c[1])-(a[1]-c[1])*(b[0]-c[0]);
}

int dist(vc &a, vc &b) {
    return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
}

int main() {
    int N;
    cin >> N;
    vc2 S(N, vc(2)),T(N, vc(2));
    rep(i, N) cin >> S.at(i).at(0) >> S.at(i).at(1);
    rep(i, N) cin >> T.at(i).at(0) >> T.at(i).at(1);
    if(N == 1) {
        cout << "Yes" << endl;
        return 0;
    }
    else if(N == 2) {
        if(dist(S.at(0), S.at(1)) == dist(T.at(0),T.at(1))) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }
    vc2 dS(N, vc(3));
    rep(i, N) {
        dS.at(i).at(0) = dist(S.at(0),S.at(i));
        dS.at(i).at(1) = dist(S.at(1),S.at(i));
        dS.at(i).at(2) = CrossProduct(S.at(0),S.at(1),S.at(i));
    }
    sort(ALL(dS));
    rep(i, N) {
        rep(j, N) {
            if(i == j) continue;
            vc2 dT(N, vc(3));
            rep(k, N) {
                dT.at(k).at(0) = dist(T.at(i), T.at(k));
                dT.at(k).at(1) = dist(T.at(j), T.at(k));
                dT.at(k).at(2) = CrossProduct(T.at(i), T.at(j), T.at(k));
            }
            sort(ALL(dT));
            /*rep(k, N) {
                cout << dT.at(k).at(0) << " ";
                cout << dT.at(k).at(1) << " ";
                cout << dT.at(k).at(2) << " ";
            }
            cout << endl;
            rep(k, N) {
                cout << dS.at(k).at(0) << " ";
                cout << dS.at(k).at(1) << " ";
                cout << dS.at(k).at(2) << " ";
            }
            cout << endl;
            cout << endl;*/
            if(dT == dS) {
                cout << "Yes" << endl;
                return 0;
            } 
        }
    }
    cout << "No" << endl;
}