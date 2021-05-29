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
    int T;
    cin >> T;

    rep(test, T) {
        int N;
        cin >> N;

        vector<ll> A(N);
        int index = 0;
        ll Amax;
        vector<ll> input;
        int index1 = N/3;
        int index2 = N*2/3;
        cout << "?" << index1 << endl;
        int preinput;
        cin >> preinput;
        input.push_back(preinput);
        cout << "?" << index2 << endl;
        cin >> preinput;
        input.push_back(preinput);
        int diff = abs(input.at(0) - input.at(1));
        while(diff < N/3) {
            cout << "?" << index1 << endl;
            preinput;
            cin >> preinput;
            input.push_back(preinput);
            cout << "?" << index2 << endl;
            cin >> preinput;
            input.push_back(preinput);
            diff++;
        }
    }
    int ans = 0;
    cout<< ans << endl;
}