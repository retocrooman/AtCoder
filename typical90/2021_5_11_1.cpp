#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

int main() {
    int N, Q;
    cin >> N;
    vector<pair<int,int>> cp(N);
    rep(i,N) cin >> cp.at(i).first >> cp.at(i).second;
    cin >> Q;
    vector<pair<int,int>> lr(Q);
    rep(i,Q) cin >> lr.at(i).first >> lr.at(i).second;
    vector<pair<int,int>> dp(N);
    rep(i,N) {
        if (cp.at(i).first == 1) {
            if (i == 0) dp.at(i).first = cp.at(i).second;
            else {
                dp.at(i).first = dp.at(i-1).first + cp.at(i).second;
                dp.at(i).second = dp.at(i-1).second;
            }
        } else {
            if (i == 0) dp.at(i).second = cp.at(i).second;
            else {
                dp.at(i).second = dp.at(i-1).second + cp.at(i).second;
                dp.at(i).first = dp.at(i-1).first;
            }
        }
    }
    vector<pair<int,int>> ans(Q);
    rep(i,Q) {
        int start=lr.at(i).first-2;
        int fin=lr.at(i).second-1;
        if (start == -1) {
            ans.at(i).first = dp.at(fin).first;
            ans.at(i).second = dp.at(fin).second;
        } else {
            ans.at(i).first = dp.at(fin).first - dp.at(start).first;
            ans.at(i).second = dp.at(fin).second - dp.at(start).second;
        }
        cout << ans.at(i).first << " " << ans.at(i).second << endl;
    }
}