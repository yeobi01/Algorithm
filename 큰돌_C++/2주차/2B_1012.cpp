#include <bits/stdc++.h>
using namespace std;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};
int M, N, K, ret, T;
int a[51][51];

void DFS(int y, int x){
    a[y][x] = 0;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if(a[ny][nx] == 1){
            DFS(ny, nx);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--){
        fill(&a[0][0], &a[0][0] + 51*51, 0);
        ret = 0;

        cin >> M >> N >> K;
        for(int i = 0; i < K; i++){
            int X, Y; cin >> X >> Y;
            a[Y][X] = 1;
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(a[i][j] == 1 && a[i][j]){
                    DFS(i, j);
                    ret++;
                }
            }
        }
        cout << ret <<"\n";
    }
    return 0;
}