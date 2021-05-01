#include <bits/stdc++.h>
using namespace std;

int main(){
    int score;
    int N, L, K;
    cin >> N >> L >> K;
    vector<int> vec(N);
    for(int i=0; i<N; i++) {
        cin >> vec.at(i);
    }
    for(int i=1; i<N; i++) {
        vec.at(i) -= vec.at(i-1);
    }
    vec.push_back(L-vec.at(N-1));
    sort(vec.rbegin(), vec.rend());
    for(int i=0; i<N-K; i++) {
        vec.pop_back();
    }
    score = vec.at(vec.size()-1) + vec.at(vec.size()-2);
    cout << score << endl;
} 