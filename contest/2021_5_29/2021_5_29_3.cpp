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
    vector<vector<int>> x(N, vector<int>(2)), y(N, vector<int>(2));
    rep(i, N) cin >> x.at(i).at(0) >> y.at(i).at(0);
    rep(i, N) {
        x.at(i).at(1) = i;
        y.at(i).at(1) = i;
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    ll maxx1x = x.at(x.size()-1).at(0) - x.at(0).at(0);
    int maxx1i = x.at(x.size()-1).at(1);
    int maxx1j = x.at(0).at(1);
    
    ll maxx2x = x.at(x.size()-2).at(0) - x.at(0).at(0);
    int maxx2i = x.at(x.size()-2).at(1);
    int maxx2j = x.at(0).at(1);

    ll maxx3x = x.at(x.size()-1).at(0) - x.at(1).at(0);
    int maxx3i = x.at(x.size()-1).at(1);
    int maxx3j = x.at(1).at(1);

    if (maxx2x < maxx3x) {
        maxx2x = maxx3x;
        maxx2i = maxx3i;
        maxx2j = maxx3j;
    }

    ll maxy1y = y.at(y.size()-1).at(0) - y.at(0).at(0);
    int maxy1i = y.at(y.size()-1).at(1);
    int maxy1j = y.at(0).at(1);

    ll maxy2y = y.at(y.size()-2).at(0) - y.at(0).at(0);
    int maxy2i = y.at(y.size()-2).at(1);
    int maxy2j = y.at(0).at(1);

    ll maxy3y = y.at(y.size()-1).at(0) - y.at(1).at(0);
    int maxy3i = y.at(y.size()-1).at(1);
    int maxy3j = y.at(1).at(1);

    if (maxy2y < maxy3y) {
        maxy2y = maxy3y;
        maxy2i = maxy3i;
        maxy2j = maxy3j;
    }

    if (maxx2x < maxy2y) {
        maxx2x = maxy2y;
        maxx2i = maxy2i;
        maxx2j = maxy2j;
    }

    if (maxx1i != maxy1i || maxx1j != maxy1j) {
        if (maxx1x < maxy1y && maxx1x > maxx2x) cout << maxx1x <<endl;
        else if (maxx1x > maxy1y && maxx2x < maxy1y) cout << maxy1y << endl;
        else cout << maxx2x << endl;
    } else {
        cout << maxx2x << endl;
    }
}