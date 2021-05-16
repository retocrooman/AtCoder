#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;
const double pi=3.1415926535;

int main() {
    double t,l,x,y,q;
    cin >> t >> l >> x >> y >> q;
    vector<int> e(q);
    rep(i,q) cin >> e.at(i);
    for(auto a : e) {
        double radian = double(a/t-0.25)*pi*2;
        double e_y = -cos(radian) * l/2;
        double e_z = l/2 + sin(radian) * l/2;
        double dist1 = sqrt(x*x + (e_y-y)*(e_y-y));
        double dist2 = e_z;
        double ans = atan(dist2/dist1);
        cout << fixed << setprecision(8) << ans/pi/2*360 << endl;
    }
}