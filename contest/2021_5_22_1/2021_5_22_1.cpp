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

    rep(i, 1000) {

        //入力
        vector<int> input(4);
        rep(j, 4) cin >> input.at(j);

        //通った道
        vector<int> usei(0), usej(0);
        usei.push_back(input.at(0));
        usej.push_back(input.at(1));

        int x = input.at(1);
        int y = input.at(0);
        int xplus = 0;
        int yplus = 0;
        if (x < input.at(3)) xplus = 1;
        if (x > input.at(3)) xplus = -1;
        if (y < input.at(2)) yplus = 1;
        if (y > input.at(2)) yplus = -1;

        //経路探索
        while (x != input.at(3)) {
            //ｘの残りをうめる
            if (y == input.at(2)) {
                while (x != input.at(3)) {
                    x += xplus;
                    usei.push_back(y);
                    usej.push_back(x);
                    cout << (xplus == 1 ? "R" : "L") << flush;
                }
                break;
            }

            //短い道の方を選択する
            if (dp.at(y*30 + x).at(y*30 + x+xplus) < dp.at(y*30 + x).at((y+yplus)*30 + x)) {
                x += xplus;
                usei.push_back(y);
                usej.push_back(x);
                cout << (xplus == 1 ? "R" : "L") << flush;
            } else {
                y += yplus;
                usei.push_back(y);
                usej.push_back(x);
                cout << (yplus == 1 ? "D" : "U") << flush;
            }
        }
        
        //yの残りをうめる
        while (y != input.at(2)) {
            y += yplus;
            usei.push_back(y);
            usej.push_back(x);
            cout << (yplus == 1 ? "D" : "U") << flush;
        }
        cout << endl;

        //入力
        int output;
        cin >> output;

        //点数の平均を計算
        vec_output.push_back(output);
        int sum = 0;
        for (int a : vec_output) {
            sum += a;
        }
        int ave = sum / vec_output.size();

        rep(j, usei.size()-1) {
            int a = usei.at(j);
            int b = usej.at(j);
            int c = usei.at(j+1);
            int d = usej.at(j+1);
            //cout << a << " " << b << " " << c << " " << d << endl;
            dp.at(a*30+b).at(c*30+d) += output - ave;
        }
    }
}
