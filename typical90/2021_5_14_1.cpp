#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define ll long long
const ll INF=1LL<<60;

int main() {
    int N;
    cin >> N;
    vector<int> A(N),B(N);
    rep(i,N) cin >> A.at(i);
    rep(i,N) cin >> B.at(i);
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    ll sum=0;
    rep(i,N) sum += abs(A.at(i)-B.at(i));
    cout << sum << endl;
}