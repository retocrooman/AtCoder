#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;
const ll mod = 1000000007;
const double pi=3.1415926535;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
 
int main() {
    int N,K;
    cin >> N >> K;
    vector<vector<int>> A(N, vector<int>(N));
    rep(i, N) {
        rep(j ,N) cin >> A.at(i).at(j);
    }
    
    
    vector<vector<int>> S(N+1, vector<int>(N+1));
    int ng = -1;
    int ok = 1000000000;
    int mid;
    bool ext;
    int lim = ((K*K)/2) + 1;
    while((ng+1) < ok) {
        mid = (ng + ok) / 2;
        rep(i, N) {
            rep(j, N) {
                S.at(i+1).at(j+1) = S.at(i+1).at(j) + S.at(i).at(j+1) - S.at(i).at(j);
                if (A.at(i).at(j) > mid) S.at(i+1).at(j+1)++;
            }
        }
        ext = false;
        rep(i, N-K+1) {
            rep(j, N-K+1) {
                if ((S.at(i+K).at(j+K) + S.at(i).at(j) - S.at(i).at(j+K) - S.at(i+K).at(j)) < lim) ext = true;
            }
        }
        if (ext) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
}