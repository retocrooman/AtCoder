#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;
const double pi=3.1415926535;

int main() {
    int H, W;
    cin >> H >> W;
    int a = (H+1) / 2;
    int b = (W+1) / 2;
    int ans  = a * b;
    if (H == 1) ans = W;
    if (W == 1) ans = H;
    cout << ans << endl;
}