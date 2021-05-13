#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define ll long long
const ll INF=1000000000;
const int Large=100009;
ll N,M;
vector<ll> A(Large),B(Large),C(Large);

vector<ll> dist(Large),dist1(Large),distN(Large);
vector<vector<pair<int,ll>>> G(Large);

void dijkstra(int n) {
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> Q;
    rep(i,N) dist.at(i+1) = INF;
    dist.at(n)=0;
    Q.push(make_pair(0,n));
    while (!Q.empty()) {
        int pos=Q.top().second;
        Q.pop();
        rep(i,G.at(pos).size()) {
            int to=G.at(pos).at(i).first;
            ll cost=G.at(pos).at(i).second;
            if (dist.at(to) > dist.at(pos)+cost) {
                dist.at(to) = dist.at(pos)+cost;
                Q.push(make_pair(dist.at(to),to));
            }
        }
    }
}

int main() {
    cin >> N >> M;
    rep(i,M) {
        cin >> A.at(i+1) >> B.at(i+1) >> C.at(i+1);
        G.at(A.at(i+1)).push_back(make_pair(B.at(i+1),C.at(i+1)));
        G.at(B.at(i+1)).push_back(make_pair(A.at(i+1),C.at(i+1)));
    }
    dijkstra(1);
    rep(i,N) dist1.at(i+1) = dist.at(i+1);
    dijkstra(N);
    rep(i,N) distN.at(i+1) = dist.at(i+1);
    rep(i,N) {
        ll Answer=dist1.at(i+1)+distN.at(i+1);
        cout << Answer << endl;
    }
}