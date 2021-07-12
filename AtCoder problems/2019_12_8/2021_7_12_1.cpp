#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i=0; i<(ll)(n); i++)
#define rev_rep(i, n) for (ll i=(n); i > 0; i--)
#define REP(i, n) for (ll i=1; i<=(ll)(n); i++)
#define FOR(i, n, m) for (ll i=(n); i<=(ll)(m); i++)
#define rev_FOR(i, n, m) for (ll i=(n); i>=(ll)(m); i--)
#define ll long long
#define ull unsigned long long
#define vc vector<ll>
#define vc2 vector<vector<ll>>
#define vc3 vector<vector<vector<ll>>>
#define vcd vector<double>
#define vc2d vector<vector<double>>
#define vc3d vector<vector<vector<double>>>
#define vcs vector<string>
#define vc2s vector<vector<string>>
#define vc3s vector<vector<vector<string>>>
#define ALL(vec) vec.begin(),vec.end()
const ll INF=1LL<<60;
const ll mod = 1000000007;
const double pi=3.1415926535;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T>bool ch_max(T &a, const T &b) {if (a<b) {a = b; return 1; } return 0;}
template<class T>bool ch_min(T &a, const T &b) {if (b<a) {a = b; return 1; } return 0;}

int N;
vector<int> A(16);
vector<vector<int>> x(16, vector<int>(16));
vector<vector<int>> y(16, vector<int>(16));
int answer = 0;

void BitSearch() {
    //bitで部分集合を表す
    for(int bit=0; bit<(1<<N); bit++) {
        bool ok = true;
        int sum = 0;
        for(int i=0; i<N; i++) {
            if(bit&(1<<i)) {
                //正直者をカウント
                sum++;
                for(int j=0; j<A.at(i); j++) {
                    bool p,q;
                    //該当の人を調べる
                    if(bit&(1<<x.at(i).at(j))) p = true;
                    else p = false;
                    //証言を調べる
                    if(y.at(i).at(j)) q = true;
                    else q = false;
                    //bitと証言が異なれば偽
                    if(p != q) ok = false;
                }
            }
        }
        //問題なければ答えを更新
        if(ok) answer = max(answer, sum);
    }
}

int main() {
    //入力
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> A.at(i);
        for(int j=0; j<A.at(i); j++) {
            cin >> x.at(i).at(j) >> y.at(i).at(j);
            //0からN-1で人を表すので-1する
            x.at(i).at(j)--;
        }
    }
    //bit全探索
    BitSearch();
    //出力
    cout << answer << endl;
}