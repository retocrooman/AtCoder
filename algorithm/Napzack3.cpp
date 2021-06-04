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
    vector<long long> dp(N*1000+1);
    //価値を実現できないところはINFを挿入
    long long INF = 1LL<<60;
    for(int i=1; i <= N*1000; i++)  dp.at(i) = INF;
    for(int i=0; i < N; i++) {
        //漸化式で重さを計算し比べて挿入
        for(int j=N*1000; j >= 0; j--) {
            //添え字が負になるｊが出たら終了
            if (j - vw.at(i+1).first < 0) break;
            //漸化式の計算
            long long weight = dp.at(j - vw.at(i+1).first) + vw.at(i+1).second;
            //上の値の重さと漸化式で出した重さを比較
            dp.at(j) = min(dp.at(j), weight);
        }
    }
    //DPテーブルを用いて値がW以下である価値の最大を求める
    int ans = 0;
    for (int i=N*1000; i >= 0; i--) {
        //W以下のときのiが答え
        if (dp.at(i) <= W) {
            ans = i;
            break;
        }
    }
    //出力
    cout<< ans << endl;
}