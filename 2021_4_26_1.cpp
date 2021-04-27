#include <bits/stdc++.h>
using namespace std;
int main()
{
    string res;
    int a, b, cnt = 1;
    int cnt_u = 10, cnt_d = 10, cnt_l = 10, cnt_r = 10;
    cin >> a >> b;
    vector<vector<vector<int>>> tile(50, vector<vector<int>>(50, vector<int>(3)));
    vector<vector<int>> point(50, vector<int>(50));
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            cin >> tile.at(i).at(j).at(0);
            if (i > 0 && tile.at(i).at(j).at(0) == tile.at(i - 1).at(j).at(0)) {
                tile.at(i).at(j).at(1) = tile.at(i-1).at(j).at(1);
            } else if (j > 0 && tile.at(i).at(j).at(0) == tile.at(i).at(j - 1).at(0)) {
                tile.at(i).at(j).at(1) = tile.at(i).at(j - 1).at(1);
            } else {
                tile.at(i).at(j).at(1) = cnt;
                cnt++;
            }
        }
    }
    
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            cin >> point.at(i).at(j);
        }
    }

    while (true) {
        bool u = true, d = true, l = true, r = true;
        tile.at(a).at(b).at(2) = 1;
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 50; j++) {
                if (tile.at(i).at(j).at(1) == tile.at(a).at(b).at(1)) {
                    tile.at(i).at(j).at(2) = 1;
                }
            }
        }
        if (a == 0) {
            u = false;
        }
        if (a == 49) {
            d = false;
        }
        if (b == 0) {
            l = false;
        }
        if (b == 49) {
            r = false;
        }
        if (u && tile.at(a-1).at(b).at(2) == 1) {
            u = false;
        }
        if (d && tile.at(a+1).at(b).at(2) == 1) {
            d = false;
        }
        if (l && tile.at(a).at(b-1).at(2) == 1) {
            l = false;
        }
        if (r && tile.at(a).at(b+1).at(2) == 1) {
            r = false;
        }
        if (!u && !d && !l && !r) break;
        vector<vector<int>> sort_point = {{0,0}, {0,1}, {0,2}, {0,3}};
        if (u) sort_point.at(0).at(0) = point.at(a-1).at(b) * cnt_u;
        if (d) sort_point.at(1).at(0) = point.at(a+1).at(b) * cnt_d;
        if (l) sort_point.at(2).at(0) = point.at(a).at(b-1) * cnt_l;
        if (r) sort_point.at(3).at(0) = point.at(a).at(b+1) * cnt_r;
        sort(sort_point.begin(), sort_point.end());
        for (int i=3; i>=0; i--) {
          if (sort_point.at(i).at(1) == 0 && u) {
            a--;
            res += "U";
            cnt_u++;
            break;
          } else if (sort_point.at(i).at(1) == 1 && d) {
            a++;
            res += "D";
            cnt_d++;
            break;
          } else if (sort_point.at(i).at(1) == 2 && l) {
            b--;
            res += "L";
            cnt_l++;
            break;
          } else if (sort_point.at(i).at(1) == 3 && r) {
            b++;
            res += "R";
            cnt_r++;
            break;
          }
        }
    }
    cout << res << endl;
    cout << res.size() << endl;
    return 0;
}