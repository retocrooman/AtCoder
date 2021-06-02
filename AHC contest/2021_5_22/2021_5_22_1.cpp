#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;
const double pi=3.1415926535;

int main() {
    vector<vector<int>> dp(900, vector<int>(900));
    vector<int> vec_output;
    //通った道
    vector<vector<int>> usei(1000), usej(1000);
    vector<int> usedoutput(1000);

    rep(i, 1000) {

        //入力
        vector<int> input(4);
        rep(j, 4) cin >> input.at(j);

        usei.at(i).push_back(input.at(0));
        usej.at(i).push_back(input.at(1));

        int x = input.at(1);
        int y = input.at(0);
        int xplus = 0;
        int yplus = 0;
        if (x < input.at(3)) xplus = 1;
        if (x > input.at(3)) xplus = -1;
        if (y < input.at(2)) yplus = 1;
        if (y > input.at(2)) yplus = -1;
        bool X = false;

        //経路探索
        while (x != input.at(3)) {
            //ｘの残りをうめる
            if (y == input.at(2)) {
                while (x != input.at(3)) {
                    x += xplus;
                    usei.at(i).push_back(y);
                    usej.at(i).push_back(x);
                    cout << (xplus == 1 ? "R" : "L") << flush;
                }
                break;
            }

            //探索済みか近いかを調べる
            if (dp.at(y*30 + x).at(y*30 + x+xplus) == 0 && dp.at(y*30 + x).at((y+yplus)*30 + x) == 0) {
                X = !X;
            } else if (dp.at(y*30 + x).at(y*30 + x+xplus) == 0) {
                X = true;
            } else if (dp.at(y*30 + x).at((y+yplus)*30 + x) == 0) {
                X = false;
            } else if (dp.at(y*30 + x).at(y*30 + x+xplus) < dp.at(y*30 + x).at((y+yplus)*30 + x)) {
                X = true;
            } else if (dp.at(y*30 + x).at(y*30 + x+xplus) > dp.at(y*30 + x).at((y+yplus)*30 + x)) {
                X = false;
            }

            if (X) {
                x += xplus;
                usei.at(i).push_back(y);
                usej.at(i).push_back(x);
                cout << (xplus == 1 ? "R" : "L") << flush;
            } else {
                y += yplus;
                usei.at(i).push_back(y);
                usej.at(i).push_back(x);
                cout << (yplus == 1 ? "D" : "U") << flush;
            }
        }
        
        //yの残りをうめる
        while (y != input.at(2)) {
            y += yplus;
            usei.at(i).push_back(y);
            usej.at(i).push_back(x);
            cout << (yplus == 1 ? "D" : "U") << flush;
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

        rep(j, put_output.size()) {
            put_output.at(j) -= usedoutput.at(j);
            usedoutput.at(j) = put_output.at(j);
            rep(k, usei.at(j).size()-1) {
                int a = usei.at(j).at(k);
                int b = usej.at(j).at(k);
                int c = usei.at(j).at(k+1);
                int d = usej.at(j).at(k+1);
                //cout << a*30+b << " " << c*30+d << endl;
                dp.at(a*30+b).at(c*30+d) += put_output.at(j);
                dp.at(c*30+d).at(a*30+b) += put_output.at(j);
            }
        }

        /*rep(j, 29) {
            rep(k, 29) {
                cout << " " << dp.at(j*30+k).at(j*30+k+1);
            }
            cout << endl;
            rep(k, 30) {
                cout << dp.at(j*30+k).at((j+1)*30+k) << " ";
            }
            cout << endl;
        }*/
    }
}
