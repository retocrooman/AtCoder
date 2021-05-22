#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;
const double pi=3.1415926535;

int main() {
    string S;
    cin >> S;
    rep(i, S.size()) {
        if (S.at(i) == '6') S.at(i) = '9';
        else if (S.at(i) == '9') S.at(i) = '6';
    }
    string T;
    rep(i, S.size()) {
        T.push_back(S.at(S.size()-i-1));
    }
    cout << T << endl;
}