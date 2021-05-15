#include <bits/stdc++.h>
using namespace std;
#define Rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define For(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;

int main() {
    string S;
    cin >> S;
    vector<int> a,b,c;
    Rep(i,S.size()) {
        char s=S.at(i);
        if (s=='o') a.push_back(i);
        if (s=='x') b.push_back(i);
        if (s=='?') c.push_back(i);
    }
    int cnt = 0;
    Rep(i,10) {
        bool no=false;
        Rep(I,b.size()) if(i==b.at(I)) no = true;
        if (no) continue;
        Rep(j,10) {
            bool no=false;
            Rep(I,b.size()) if(j==b.at(I)) no = true;
            if (no) continue;
            Rep(k,10) {
            bool no=false;
                Rep(I,b.size()) if(k==b.at(I)) no = true;
                if (no) continue;
                Rep(l,10) {
                    bool no=false;
                    Rep(I,b.size()) if(l==b.at(I)) no = true;
                    if (no) continue;
                    bool can=true;
                    Rep(I,a.size()) {
                        if (i!=a.at(I) && j!=a.at(I) && k!=a.at(I)&& l!=a.at(I)) can = false;
                    }
                    if (can) cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
}