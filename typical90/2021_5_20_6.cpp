#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define FOR(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;
const double pi=3.1415926535;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    rep(i, N) cin >> a.at(i);
    set<int> st;
    deque<int> deq;
    int ans = -1;
    int start = 0;
    rep(i, N) {
        st.insert(a.at(i));
        deq.push_back(a.at(i));
        if (st.size() > K) {
            int end = i;
            ans = max(ans, end - start);
            while (st.size() > K) {
                int a = deq.front();
                deq.pop_front();
                start++;
                bool can = true;
                for (int b : deq) {
                    if (a == b) can = false;
                }
                if (can) {
                    st.erase(a);
                }
            }
        }
    }
    if (ans == -1) ans = N;
    cout << ans << endl;
}