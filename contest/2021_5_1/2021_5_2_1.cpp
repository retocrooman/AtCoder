#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vec(3000, vector<int>(5));
int N;

bool solve(int n) {
    for (int i=0; i<N; i++) {
        for (int j=i+1; i<N; j++) {
            for (int k=j+1; k<N; k++) {
                int a=0,b=0,c=0,d=0,e=0;
                for (int l=0; l<5; l++) {
                    a = max(vec.at(i).at(l),vec.at(j).at(l),vec.at(k).at(l));
                }
                for (int l=0; l<5; l++) {
                    b = max(vec.at(i).at(l),vec.at(j).at(l),vec.at(k).at(l));
                }
                for (int l=0; l<5; l++) {
                    c = max(vec.at(i).at(l),vec.at(j).at(l),vec.at(k).at(l));
                }
                for (int l=0; l<5; l++) {
                    d = max(vec.at(i).at(l),vec.at(j).at(l),vec.at(k).at(l));
                }
                for (int l=0; l<5; l++) {
                    e = max(vec.at(i).at(l),vec.at(j).at(l),vec.at(k).at(l));
                }
                if (a>=n && b>=n && c>=n && d>=n && e>=n) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<5; j++) {
            cin >> vec.at(i).at(j);
        }
    }
    int left = 1;
    int right = 1000000000;
    while (left-right > 1) {
        int mid = left + (right-left) / 2;
        if (solve(mid) == false) right = mid;
        else left = mid;
    }
    cout << left << endl;
}