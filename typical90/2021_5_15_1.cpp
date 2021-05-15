#include <bits/stdc++.h>
using namespace std;
#define Rep(i, n) for (int i=0; i<(int)(n); i++)
#define REP(i, n) for (int i=1; i<=(int)(n); i++)
#define For(i, n, m) for (int i=(n); i<=(int)(m); i++)
#define ll long long
const ll INF=1LL<<60;

int main() {
    int N;
    vector<int> vec(3);
    cin >> N >> vec.at(0) >> vec.at(1) >> vec.at(2);
    sort(vec.begin(), vec.end());
    int a=vec.at(2),b=vec.at(1),c=vec.at(0);
    vector<int> ans;
    Rep(i,10000) {
        int sum1 = N - a*i;
        if (sum1 < 0) break;
        Rep(j,10000-i) {
            int sum2=sum1-j*b;
            if (sum2 < 0) break;
            if (sum2%c != 0) continue;
            int k=sum2/c;
            if (i+j+k >= 10000) continue;
            ans.push_back(i+j+k);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.front() << endl;
}