#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

int main() {
    int N;
    long K;
    cin >> N >> K;
    vector<vector<long long>> dp(4,vector<long long>(3*N+4));
    dp.at(0).at(0) = 1;
    rep(i,3) {
        rep(j,i*N+1) {
            dp.at(i+1).at(j+1) += dp.at(i).at(j);
            dp.at(i+1).at(j+N+1) -= dp.at(i).at(j);
        }
        rep(j,(i+1)*N) {
            dp.at(i+1).at(j+1) += dp.at(i+1).at(j);
        }
    }
    int sum;
    for(int i=3; i<=3*N; i++) {
        if(K<=dp.at(3).at(i)) {
            sum = i;
            break;
        }
        else {
            K -= dp.at(3).at(i);
        }
    }
    rep(i,N) {
        int ans_1 = i+1;
        int jmin=max(1,sum-ans_1-N);
        int jmax=min(N,sum-ans_1-1);
        if(jmin>jmax) continue;
        if(K>(jmax-jmin+1)) {
            K -= jmax-jmin+1;
            continue;
        }
        int ans_2=jmin+K-1;
        int ans_3=sum-ans_1-ans_2;
        cout << ans_1 << " " << ans_2 << " " << ans_3 << endl;
        break;
    }
}