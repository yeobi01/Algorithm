#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int N, arr[20][20], dp[20][20][3];

bool check(int y, int x, int d){
    if(d == 0 || d == 2){
        if(!arr[y][x]) return true;
    } else if(d == 1){
        if(arr[y][x] == 0 && arr[y - 1][x] == 0 && arr[y][x - 1] == 0) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }
    dp[0][1][0] = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][0];
            if(check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][0];

            if(check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][2];
            if(check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][2];

            if(check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][1];
            if(check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][1];
            if(check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][1];
        }
    }
    int ret = dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];
    cout << ret << "\n";
    return 0;
}