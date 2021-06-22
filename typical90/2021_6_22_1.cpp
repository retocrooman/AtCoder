#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i=0; i<(ll)(n); i++)
#define rev_rep(i, n) for (ll i=(n); i > 0; i--)
#define REP(i, n) for (ll i=1; i<=(ll)(n); i++)
#define FOR(i, n, m) for (ll i=(n); i<=(ll)(m); i++)
#define rev_FOR(i, n, m) for (ll i=(n); i<=(ll)(m); i--)
#define ll long long
#define vc vector<ll>
#define vc2 vector<vector<ll>>
#define vc3 vector<vector<vector<ll>>>
#define vcd vector<double>
#define vc2d vector<vector<double>>
#define vc3d vector<vector<vector<double>>>
#define vcs vector<string>
#define vc2s vector<vector<string>>
#define vc3s vector<vector<vector<string>>>
#define ALL(vec) vec.begin(),vec.end()
const ll INF=1LL<<60;
const ll mod = 1000000007;
const double pi=3.1415926535;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T>bool ch_max(T &a, const T &b) {if (a<b) {a = b; return 1; } return 0;}
template<class T>bool ch_min(T &a, const T &b) {if (b<a) {a = b; return 1; } return 0;}

class union_find {
private:
	int N;
	vector<int> par;
public:
	union_find() : N(0), par() {}
	union_find(int N_) : N(N_) {
		par.resize(N);
		for (int i = 0; i < N; ++i) {
			par[i] = i;
		}
	}
	int root(int x) {
		if (x == par[x]) return x;
		return par[x] = root(par[x]);
	}
	void link(int x, int y) {
		par[root(x)] = root(y);
	}
	bool connected(int x, int y) {
		return root(x) == root(y);
	}
};

int main() {
	int N, Q;
	cin >> N >> Q;
	vc T(Q), X(Q), Y(Q), V(Q);
	rep(i, Q) {
		cin >> T.at(i) >> X.at(i) >> Y.at(i) >> V.at(i);
		X.at(i)--;
		Y.at(i)--;
	}

	vc sum(N-1);
	rep(i, Q) {
		if(T.at(i) == 0) sum.at(X.at(i)) = V.at(i);
	}
	vc potential(N);
	rep(i, N-1) {
		potential.at(i+1) = sum.at(i) - potential.at(i);
	}
	union_find uf(N);
	rep(i, Q) {
		if(T.at(i) == 0) uf.link(X.at(i), Y.at(i));
		if(T.at(i) == 1) {
			if(!uf.connected(X.at(i), Y.at(i))) {
				cout << "Ambiguous" << endl;
			}
			else if((X.at(i) + Y.at(i)) % 2 == 0) {
				cout << V.at(i) + (potential.at(Y.at(i)) - potential.at(X.at(i))) << endl;
			}
			else {
				cout << -V.at(i) + (potential.at(Y.at(i)) + potential.at(X.at(i))) << endl;
			}
		}
	}
}