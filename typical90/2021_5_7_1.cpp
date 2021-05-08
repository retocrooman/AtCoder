#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

int N;
vector<int> A(300000), B(300000), ans(300000);

void absoluteAB(int n) {
    int left=0;
    int right=N-1;
    int mid=(left+right)/2;
    int ans;
    if (B.at(n) < A.at(0)) {
        cout << A.at(0)-B.at(n) << endl;
        return;
    } else if (B.at(n) > A.at(N-1)) {
        cout << B.at(n)-A.at(N-1) << endl;
        return;
    }
    while (right-left > 1) {
        mid=(left+right)/2;
        if (A.at(mid) < B.at(n)) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    ans = B.at(n)-A.at(left);
    if (ans > A.at(right)-B.at(n)) ans = A.at(right)-B.at(n);
    cout << ans << endl;
}

int main() {
    cin >> N;
    rep(i,N) cin >> A.at(i);
    int Q;
    cin >> Q;
    rep(i,Q) cin >> B.at(i);
    sort(A.begin(), A.begin()+N);
    rep(i,Q) absoluteAB(i);
}