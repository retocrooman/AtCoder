#include <bits/stdc++.h>
using namespace std;


int main(){
    string S;
    deque<char> T;
    string ans;
    cin >> S;
    bool rev = false;
    for (int i=0; i<S.size(); i++) {
        char s = S.at(i);
        if (s == 'R') {
            rev = !rev;
        } else if (rev) {
            if (s == T.front()) T.pop_front();
            else T.push_front(s);
        } else {
            if (s == T.back()) T.pop_back();
            else T.push_back(s);
        }
    }
    if (rev) reverse(T.begin(), T.end());
    for (int i=0; i<T.size(); i++) {
        ans += T.at(i);
    }
    cout << ans << endl;
}