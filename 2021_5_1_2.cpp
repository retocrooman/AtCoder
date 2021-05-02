#include <bits/stdc++.h>
using namespace std;

int main(){
    double ans;
    int N, D, H;
    cin >> N >> D >> H;
    vector<vector<int>> vec(N, vector<int>(2));
    for (int i=0; i<N; i++) {
        cin >> vec.at(i).at(0) >> vec.at(i).at(1);
    }
    int max = N;
    for (int i=0; i<N; i++) {
        int h, d;
        double ans1;
        h = H - vec.at(i).at(1);
        d = D - vec.at(i).at(0);
        ans1 = (double)(d*H - h*D) / d;
        if (ans < ans1) ans = ans1; 
    }
    cout << fixed << setprecision(20) << ans << endl;
}