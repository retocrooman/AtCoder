#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;
const ll mod = 1000000007;
const double pi=3.1415926535;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    //入力
    int N;
    long long W;
    cin >> N >> W;
    vector<pair<long long, long long>> vw(N+1);
    for(int i=1; i <= N; i++) cin >> vw.at(i).first >> vw.at(i).second;
    //DPの計算
    vector<vector<long long>> dp(N+1, vector<long long>(W+1));
    for(int i=0; i < N; i++) {
        //下におろす
        for(int j=0; j <= W; j++) dp.at(i+1).at(j) = dp.at(i).at(j);
        //漸化式で価値を計算し比べて挿入
        for(int j=0; j <= W; j++) {
            //添え字が負になるｊは飛ばす
            if (j - vw.at(i+1).second < 0) continue;
            //漸化式の計算
            long long value = dp.at(i).at(j - vw.at(i+1).second) + vw.at(i+1).first;
            //上の値の価値と漸化式で出した価値を比較
            dp.at(i+1).at(j) = max(dp.at(i+1).at(j), value);
        }
    }
    //出力
    cout<< dp.at(N).at(W) << endl;
}