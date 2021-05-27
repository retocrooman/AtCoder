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
    int N;
    cin >> N;
    vector<int> h(N+1);
    REP(i, N) cin >> h.at(i);
    
    vector<int> dp(N+1);
    dp.at(1) = 0;
    dp.at(2) = abs(h.at(2) - h.at(1));
    REP(i, N-2) dp.at(i+2) = min(dp.at(i+1) + abs(h.at(i+2) - h.at(i+1)), dp.at(i) + abs(h.at(i+2) - h.at(i))); 
    cout<< dp.at(N) << endl;
}