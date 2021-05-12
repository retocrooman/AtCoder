#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

class UnionFind {
public:
        vector<int> par;
        void init(int sz) {
            par.resize(sz, -1);
        }
        int root(int pos) {
            if (par.at(pos) == -1) return pos;
            par.at(pos) = root(par.at(pos));
            return par.at(pos);
        }
        void unite(int u, int v) {
            u = root(u);
            v = root(v);
            if (u == v) return;
            par.at(u) = v;
        }
        bool same(int u, int v) {
            if (root(u) == root(v)) return true;
            return false;
        }
};

int H,W,Q;

UnionFind UF;
vector<vector<bool>> used(2009,vector<bool>(2009));

void query1(int px, int py) {
    vector<int> dx={-1, 0, 1, 0};
    vector<int> dy={0, 1, 0, -1};
    rep(i,4) {
        int sx = px+dx.at(i);
        int sy = py+dy.at(i);
        if (used.at(sx).at(sy)==false) continue;
        int hash1 = (px-1)*W + (py-1);
        int hash2 = (sx-1)*W + (sy-1);
        UF.unite(hash1, hash2);
    }
    used.at(px).at(py) = true;
}

bool query2(int px,int py,int qx,int qy) {
    if (used.at(px).at(py)==false || used.at(qx).at(qy)==false) return false;
    int hash1 = (px-1)*W + (py-1);
    int hash2 = (qx-1)*W + (qy-1);
    if (UF.same(hash1, hash2)==true) return true;
    return false;
}

int main(){
    cin >> H >> W >> Q;
    UF.init(H*W);
    rep(i,Q) {
        int ty;
        cin >> ty;
        if (ty == 1) {
            int x, y;
            cin >> x >> y;
            query1(x, y);
        } else {
            int xa,xb,ya,yb;
            cin >> xa >> xb >> ya >> yb;
            bool Answer=query2(xa,xb,ya,yb);
            if (Answer==true) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}
