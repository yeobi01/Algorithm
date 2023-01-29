#include<bits/stdc++.h>
using namespace std;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int N, M, K, arr[51][51];
vector<pair<int, int>> vv;
vector<int> v_idx;
struct A{
    int y, x, cnt;
};
vector<A> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < K; i++){
        int r, c, s;
        cin >> r >> c >> s; r--; c--;
        v.push_back({r, c, s});
        v_idx.push_back(i);
    }

    return 0;
}