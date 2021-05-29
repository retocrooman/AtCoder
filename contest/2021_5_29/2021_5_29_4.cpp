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
    vector<ll> R,G,B;
    rep(i, 2*N) {
        ll a;
        char c;
        cin >> a >> c;
        if (c == 'R') R.push_back(a);
        if (c == 'G') G.push_back(a);
        if (c == 'B') B.push_back(a);
    }
    
    vector<ll> vec1, vec2, vec3;
    if (R.size()%2 == 0 && G.size()%2 == 0 && B.size()%2 == 0) {
        cout << 0 << endl;
        return 0;
    }
    if (R.size()%2 == 0) {
        for(ll a : G) vec1.push_back(a);
        for(ll a : B) vec2.push_back(a);
        for(ll a : R) vec3.push_back(a);
    }
    if (G.size()%2 == 0) {
        for(ll a : R) vec1.push_back(a);
        for(ll a : B) vec2.push_back(a);
        for(ll a : G) vec3.push_back(a);
    }
    if (B.size()%2 == 0) {
        for(ll a : R) vec1.push_back(a);
        for(ll a : G) vec2.push_back(a);
        for(ll a : B) vec3.push_back(a);
    }

    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    sort(vec3.begin(), vec3.end());
    
    ll ans = INF;
    if(vec1.at(0) >= vec2.at(0)) {
        rep(i, vec1.size()) {
            int index = lower_bound(vec2.begin(), vec2.end(), vec1.at(i)) - vec2.begin();
            ll diff = vec1.at(i) - vec2.at(index-1);
            if (index != vec2.size()) diff = min(diff, vec2.at(index) - vec1.at(i));
            ans = min(ans, diff);
        }
    } else {
        rep(i, vec2.size()) {
            int index = lower_bound(vec1.begin(), vec1.end(), vec2.at(i)) - vec1.begin();
            ll diff = vec2.at(i) - vec1.at(index-1);
            if (index != vec1.size()) diff = min(diff, vec1.at(index) - vec2.at(i));
            ans = min(ans, diff);
        }
    }

    if (vec3.size() == 0) {
        cout << ans << endl;
        return 0;
    }
    
    ll ans1 = INF;
    ll ans2 = INF;
    if(vec1.at(0) >= vec3.at(0)) {
        rep(i, vec1.size()) {
            int index = lower_bound(vec3.begin(), vec3.end(), vec1.at(i)) - vec3.begin();
            ll diff = vec1.at(i) - vec3.at(index-1);
            if (index != vec3.size()) diff = min(diff, vec3.at(index) - vec1.at(i));
            ans1 = min(ans1, diff);
        }
    } else {
        rep(i, vec3.size()) {
            int index = lower_bound(vec1.begin(), vec1.end(), vec3.at(i)) - vec1.begin();
            ll diff = vec3.at(i) - vec1.at(index-1);
            if (index != vec1.size()) diff = min(diff, vec1.at(index) - vec3.at(i));
            ans1 = min(ans1, diff);
        }
    }

    if(vec2.at(0) >= vec3.at(0)) {
        rep(i, vec2.size()) {
            int index = lower_bound(vec3.begin(), vec3.end(), vec2.at(i)) - vec3.begin();
            ll diff = vec2.at(i) - vec3.at(index-1);
            if (index != vec3.size()) diff = min(diff, vec3.at(index) - vec2.at(i));
            ans2 = min(ans2, diff);
        }
    } else {
        rep(i, vec3.size()) {
            int index = lower_bound(vec2.begin(), vec2.end(), vec3.at(i)) - vec2.begin();
            ll diff = vec3.at(i) - vec2.at(index-1);
            if (index != vec2.size()) diff = min(diff, vec2.at(index) - vec3.at(i));
            ans2 = min(ans2, diff);
        }
    }

    cout << min(ans, ans1 + ans2) << endl;
}