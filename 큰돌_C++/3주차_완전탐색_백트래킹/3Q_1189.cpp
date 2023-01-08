#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MAX = 1501;
const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};

int R, C, K, ret, visited[6][6];
char arr[6][6];

void go(int y, int x, int cnt){
    if(y == 0 && x == C-1 && cnt == K){ ret++; return; }
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(arr[ny][nx] == 'T') continue;
        if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        go(ny, nx, cnt + 1);
        visited[ny][nx] = 0;
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> K;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> arr[i][j];
        }
    }
    visited[R-1][0] = 1;
    go(R-1, 0, 1);

    cout << ret << "\n";
    return 0;
}