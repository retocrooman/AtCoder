#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A(1<<18), B(1<<18);

const int INF = (1<<29);
vector<vector<int>> G(1<<18);
vector<int> dist(1<<18);

void getdist(int start) {
    for (int i=1; i<=N; i++) dist.at(i) = INF;
    queue<int> Q;
    Q.push(start);
    dist.at(start) = 0;
    while (!Q.empty()) {
        int pos = Q.front();
        Q.pop();
        for (int to : G.at(pos)) {
            if (dist.at(to)==INF) {
                dist.at(to) = dist.at(pos) + 1;
                Q.push(to);
            }
        }
    }
}

int main() {
    cin >> N;
    for (int i=1; i<=N-1; i++) {
        cin >> A.at(i) >> B.at(i);
        G.at(A.at(i)).push_back(B.at(i));
        G.at(B.at(i)).push_back(A.at(i));
    }
    getdist(1);
    int maxn1 = -1, maxid1 = -1;
    for (int i=0; i<=N; i++) {
        if (maxn1 < dist.at(i)) {
            maxn1 = dist.at(i);
            maxid1 = i;
        }
    }
    getdist(maxid1);
    int maxn2 = -1;
    for (int i=1; i<=N; i++) {
        maxn2 = max(maxn2, dist.at(i));
    }
    cout << maxn2+1 << endl;
}