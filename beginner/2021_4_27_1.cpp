#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

int main()
{
    int A, B, C, X, cnt=0;
    cin >> A >> B >> C >> X;
    rep(i, A+1) {
        if(500*i > X) break;
        rep(j, B+1) {
            if(500*i + 100*j > X) break;
            rep(k, C+1){
                if(500*i + 100*j + 50*k > X) break; 
                if(500*i + 100*j + 50*k == X) cnt++;
            }
        }
    }
    cout << cnt << endl;
}