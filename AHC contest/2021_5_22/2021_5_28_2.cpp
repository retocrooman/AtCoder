#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;
const double pi=3.1415926535;
 
int main() {
    vector<vector<ll>> dp(900, vector<ll>(900));
    rep(i, 900) {
        rep(j, 900) dp.at(i).at(j) = -100000000;
    }
    vector<ll> vec_output;
    //通った道
    vector<vector<int>> usei(1000), usej(1000);
    vector<ll> usedoutput(1000);
 
    rep(i, 1000) {
 
        //入力
        vector<int> input(4);
        rep(j, 4) cin >> input.at(j);
 
        int x1 = input.at(1);
        int y1 = input.at(0);
        int x2 = input.at(3);
        int y2 = input.at(2);
 
        int xplus = 1;
        int yplus = 1;
        if (x1 > x2) {
            xplus = -1;
            int a = x1;
            x1 = x2;
            x2 = a;
        }
        if (y1 > y2) {
            yplus = -1;
            int a = y1;
            y1 = y2;
            y2 = a;
        }
 
        //経路探索
        vector<vector<ll>> tile(30, vector<ll>(30));
        vector<vector<vector<int>>> useitile(30, vector<vector<int>>(30));
        vector<vector<vector<int>>> usejtile(30, vector<vector<int>>(30));
        rep(j, 30) {
            rep(k, 30) tile.at(j).at(k) = INF;
        }
        tile.at(y1).at(x1) = 0;
        FOR(j, y1, y2) {
            int I = j;
            FOR(k, x1, x2) {
                if (j == y1) break;
                int J = k;
                ll dpcost = 0;
                if (xplus == 1 && yplus == 1) dpcost = dp.at((I-1)*30+J).at(I*30+J);
                else if (xplus == 1) dpcost = dp.at((y1+y2-I+1)*30+J).at((y1+y2-I)*30+J);
                else if (yplus == 1) dpcost = dp.at((I-1)*30+x1+x2-J).at(I*30+x1+x2-J);
                else dpcost = dp.at((y1+y2-I+1)*30+x1+x2-J).at((y1+y2-I)*30+x1+x2-J);
                tile.at(I).at(J) = tile.at(I-1).at(J) + dpcost;
            }
            FOR(k, x1, x2) {
                int J = k;
                ll cost = INF;
                if (k != x1) {
                    ll dpcost = 0;
                    if (xplus == 1 && yplus == 1) dpcost = dp.at(I*30+(J-1)).at(I*30+J);
                    else if (xplus == 1) dpcost = dp.at((y1+y2-I)*30+J-1).at((y1+y2-I)*30+J);
                    else if (yplus == 1) dpcost = dp.at(I*30+x1+x2-J+1).at(I*30+x1+x2-J);
                    else dpcost = dp.at((y1+y2-I)*30+x1+x2-J+1).at((y1+y2-I)*30+x1+x2-J);
                    cost = tile.at(I).at(J-1) + dpcost;
                }
                tile.at(I).at(J) = min(tile.at(I).at(J), cost);
                if (k == x1 && j == y1) {
                    continue;
                } else if (j == y1) {
                    rep(l, useitile.at(I).at(J-1).size()) {
                        useitile.at(I).at(J).push_back(useitile.at(I).at(J-1).at(l));
                        usejtile.at(I).at(J).push_back(usejtile.at(I).at(J-1).at(l));
                    }
                    useitile.at(I).at(J).push_back(I);
                    usejtile.at(I).at(J).push_back(J-1);
                } else if (tile.at(I).at(J) == cost) {
                    rep(l, useitile.at(I).at(J-1).size()) {
                        useitile.at(I).at(J).push_back(useitile.at(I).at(J-1).at(l));
                        usejtile.at(I).at(J).push_back(usejtile.at(I).at(J-1).at(l));
                    }
                    useitile.at(I).at(J).push_back(I);
                    usejtile.at(I).at(J).push_back(J-1);
                } else {
                    rep(l, useitile.at(I-1).at(J).size()) {
                        useitile.at(I).at(J).push_back(useitile.at(I-1).at(J).at(l));
                        usejtile.at(I).at(J).push_back(usejtile.at(I-1).at(J).at(l));
                    }
                    useitile.at(I).at(J).push_back(I-1);
                    usejtile.at(I).at(J).push_back(J);
                }
                //cout << useitile.at(I).at(J).size() << " ";
            }
        }
        useitile.at(y2).at(x2).push_back(y2);
        usejtile.at(y2).at(x2).push_back(x2);
        int usesize = useitile.at(y2).at(x2).size();
        rep(j, usesize) {
            if (yplus == 1) usei.at(i).push_back(useitile.at(y2).at(x2).at(j));
            else usei.at(i).push_back(y1 + y2 - useitile.at(y2).at(x2).at(j));
            if (xplus == 1) usej.at(i).push_back(usejtile.at(y2).at(x2).at(j));
            else usej.at(i).push_back(x1 + x2 - usejtile.at(y2).at(x2).at(j));
            //cout << usei.at(i).at(j) << " ";
            //cout << usej.at(i).at(j) << endl;
        }
 
        //出力
        rep(j, usei.at(i).size()-1) {
            if (usei.at(i).at(j) == usei.at(i).at(j+1)) cout << (xplus == 1 ? "R" : "L") << flush;
            else cout << (yplus == 1 ? "D" : "U") << flush;
        }
        cout << endl;
 
        //入力
        ll output;
        cin >> output;
 
        //点数の平均を計算
        int size = usei.at(i).size();
        output *= 60;
        output /= size;
        vec_output.push_back(output);
        ll sum = 0;
        for (ll a : vec_output) {
            sum += a;
        }
        ll ave = sum / vec_output.size();
        vector<ll> put_output;
        for (ll a : vec_output) {
            put_output.push_back(a-ave);
        }
        //cout << ave << endl;
 
        rep(j, put_output.size()) {
            put_output.at(j) -= usedoutput.at(j);
            usedoutput.at(j) = put_output.at(j);
            rep(k, usei.at(j).size()-1) {
                int a = usei.at(j).at(k);
                int b = usej.at(j).at(k);
                int c = usei.at(j).at(k+1);
                int d = usej.at(j).at(k+1);
                //cout << a*30+b << " " << c*30+d << endl;
                if (dp.at(a*30+b).at(c*30+d) == -100000000) dp.at(a*30+b).at(c*30+d) = 0;
                if (dp.at(c*30+d).at(a*30+b) == -100000000) dp.at(c*30+d).at(a*30+b) = 0;
                dp.at(a*30+b).at(c*30+d) += put_output.at(j);
                dp.at(c*30+d).at(a*30+b) += put_output.at(j);
                //cout << put_output.at(j)+1 << " ";
            }
            //cout << endl;
        }
 
        /*rep(j, 10) {
            rep(k, 10) {
                cout << "# " << dp.at(j*30+k).at(j*30+k+1) << " ";
            }
            cout << endl;
            rep(k, 10) {
                cout << dp.at(j*30+k).at((j+1)*30+k) << "   ";
            }
            cout << endl;
        }*/
    }
}