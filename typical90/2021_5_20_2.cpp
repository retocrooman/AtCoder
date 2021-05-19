#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;
const double pi=3.1415926535;

vector<int> vec(1000000);

int put(int start, int end) {
    int MAX = 0;
    FOR(i, start, end) MAX = max(MAX, vec.at(i));
    FOR(i, start, end) vec.at(i) = MAX+1;
    return MAX+1;
}

int main() {
    int W;
    int N;
    cin >> W >> N;
    vector<int> l(N), r(N), lr;
    rep(i, N) {
        cin >> l.at(i) >> r.at(i);
        lr.push_back(l.at(i));
        lr.push_back(r.at(i));
    }
    sort(lr.begin(), lr.end());
    lr.erase(unique(lr.begin(),lr.end()),lr.end());
    rep(i, N) {
        l.at(i) = lower_bound(lr.begin(), lr.end(), l.at(i)) - lr.begin();
        r.at(i) = lower_bound(lr.begin(), lr.end(), r.at(i)) - lr.begin();
    }
    rep(i, N) {
        cout << put(l.at(i), r.at(i)) << endl;
    }
}