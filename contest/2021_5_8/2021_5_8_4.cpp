#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    rep (i,N) {
        cin >> vec.at(i);
    }
    rep (i,N) {
        vec.at(i) %= 200;
    }
    long long cnt=0;
    rep(i,200) {
        long long count=0;
        rep(j,N) {
            if (vec.at(j)==i) count++;
        }
        count = count*(count-1)/2;
        cnt += count;
    }
    cout << cnt << endl;
}