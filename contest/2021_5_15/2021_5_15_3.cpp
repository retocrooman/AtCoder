#include <bits/stdc++.h>
using namespace std;
#define Rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define For(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;

int main() {
    int N;
    cin >> N;
    vector<pair<int,string>> v(N);
    Rep(i,N) cin >> v.at(i).second >> v.at(i).first;
    sort(v.begin(),v.end());
    cout << v.at(N-2).second << endl;
}