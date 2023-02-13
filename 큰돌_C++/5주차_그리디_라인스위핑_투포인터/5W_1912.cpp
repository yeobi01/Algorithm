#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};

int n, psum[100001], _max = -INF, _min = INF;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> psum[0];
    for(int i = 1; i < n; i++){
        int temp; cin >> temp;
        psum[i] = max(temp, temp + psum[i - 1]);
    }
    for(int i = 0; i < n; i++){
        _max = max(_max, psum[i]);
    }
    cout << _max << "\n";
    return 0;
}