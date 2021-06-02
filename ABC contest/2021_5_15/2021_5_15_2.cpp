#include <bits/stdc++.h>
using namespace std;
#define Rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define For(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;

int main() {
    vector<int> v(3);
    cin >> v.at(0) >> v.at(1) >> v.at(2);
    sort(v.begin(), v.end());
    if (v.at(1)-v.at(0) == v.at(2)-v.at(1)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}