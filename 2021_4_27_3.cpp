#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

int main()
{
    int N, AlicePoint=0, BobPoint=0, ans=0;
    cin >> N;
    vector<int> vec(N);
    rep(i, N) {
        cin >> vec.at(i);
    }
    sort(vec.begin(), vec.end(), greater<>());
    rep(i, N) {
        if (i%2 == 0) AlicePoint += vec.at(i);
        else BobPoint += vec.at(i);
    }
    ans = AlicePoint - BobPoint;
    cout << ans << endl;
}