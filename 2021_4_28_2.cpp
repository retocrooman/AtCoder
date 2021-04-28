#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

int main()
{
    int N, Y, x = -1, y = -1, z = -1;
    cin >> N >> Y;
    rep(i,N+1) {
        if (Y-10000*i<0) break;
        rep(j,N-i+1) {
            if (Y-10000*i-5000*j<0) break;
            if (Y-10000*i-5000*j == 1000*(N-i-j)) {
                x = i;
                y = j;
                z = N-i-j;
                break;
            }
        }
    }
    cout << x << " " << y << " " << z << endl;
}