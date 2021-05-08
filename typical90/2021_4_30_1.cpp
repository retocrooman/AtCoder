#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

int N, L, K;
vector<int> vec(100000);
bool solve(int n) {
    int cnt = 0, pre = 0;
    rep(i,N) {
        if(vec.at(i)-pre >= n && L-vec.at(i) >= n) {
            cnt++;
            pre = vec.at(i);
        }
    }
    if (cnt >= K) return true;
    else return false;
}
int main()
{
    cin >> N >> L;
    cin >> K;
    rep(i,N) cin >> vec.at(i);
    int right = L;
    int left = 0;
    while (right-left > 1)
    {
        int mid = left+(right-left)/2;
        if (solve(mid) == false) right = mid;
        else left = mid;
    }
    cout << left << endl;
}