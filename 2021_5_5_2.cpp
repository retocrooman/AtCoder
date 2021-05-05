#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> hw(H, vector<int>(W));
    vector<int> h(H),w(W);
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            cin >> hw.at(i).at(j);
        }
    }
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            h.at(i) += hw.at(i).at(j);
        }
    }
    for (int i=0; i<W; i++) {
        for (int j=0; j<H; j++) {
            w.at(i) += hw.at(j).at(i);
        }
    }
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            hw.at(i).at(j) = h.at(i) + w.at(j) - hw.at(i).at(j);
            cout << hw.at(i).at(j) << " ";
        }
        cout << endl;
    }
}