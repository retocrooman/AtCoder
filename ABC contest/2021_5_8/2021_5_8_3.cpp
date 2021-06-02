#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

int main() {
    long long N, K;
    cin >> N >> K;
    rep(i, K) {
        if (N%200==0) N /= 200;
        else N = N*1000 + 200;
    }
    cout << N << endl;
}