#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int N, M, dp[51][51];
char arr[51][51];
bool check[51][51];

int go(int y, int x){
    if(check[y][x]){
        cout << "-1\n";
        exit(0);
    }
    int &ret = dp[y][x];
    if(ret) return ret;

    check[y][x] = 1;
    int t = arr[y][x] - '0';
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i] * t;
        int nx = x + dx[i] * t;
        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if(arr[ny][nx] == 'H') continue;
        ret = max(ret, go(ny, nx) + 1);
    }
    check[y][x] = 0;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }
    go(0, 0);
    cout << dp[0][0] + 1 << "\n";
    return 0;
}