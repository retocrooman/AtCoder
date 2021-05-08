#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

int main()
{
    int N, cnt=0;
    cin >> N;
    vector<int> vec(N), check(100);
    rep(i,N) {
        cin >> vec.at(i);
    }
    rep(i,N) {
        check.at(vec.at(i)-1) = 1;
    }
    rep(i,100) {
        if (check.at(i) == 1) cnt++;
    }
    cout << cnt << endl;
}