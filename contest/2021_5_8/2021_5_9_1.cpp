#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

void output(vector<int> &a) {
    cout << a.size();
    for(auto &nx : a) {
        cout << ' ' << nx;
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep (i,N) {
        cin >> A.at(i);
    }
    vector<vector<int>> vec(200,vector<int>(0));
    int cnt=min(N,8);
    for(int i=1; i<1<<cnt; i++) {
        int sig=0;
        vector<int> v;
        rep(j,cnt) {
            if(i&1<<j) {
                v.push_back(j+1);
                sig += A.at(j);
                sig %= 200;
            }
        }
        if(vec.at(sig).size() != 0) {
            cout << "yes" << endl;
            output(vec.at(sig));
            output(v);
            return 0;
        } else {
            vec.at(sig) = v;
        }
    }
    cout << "No" << endl;
}
