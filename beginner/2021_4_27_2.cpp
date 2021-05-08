#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

int main()
{
    int N, A, B, sum=0;
    cin >> N >> A >> B;
    rep(i, N+1) {
        int a=0, b=0, c=0, d=0, e=0, f=0;
        a = i / 10000;
        b = i % 10000 / 1000;
        c = i % 1000 / 100;
        d = i % 100 / 10;
        e = i % 10;
        f = a+b+c+d+e;
        if (f >= A && f <= B) sum += i; 
    }
    cout << sum << endl;
}