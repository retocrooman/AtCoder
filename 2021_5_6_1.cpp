#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

int N, K;
string S, T;
string abc={"abcdefghijklmnopqrstuvwxyz"};

int search(int n, int m) {
    int point = 0;
    while (point < abc.size()) {
        int i=n;
        for (i; i<m; i++) {
            if (S.at(i) == abc.at(point)) {
                T += S.at(i);
                return i;
            }
        }
        point++;
    }
}
int main()
{
    cin >> N >> K;
    cin >> S;
    int start=0;
    rep(i,K) {
        start = search(start, N-K+i+1);
        start++;
    }
    cout << T << endl;
}