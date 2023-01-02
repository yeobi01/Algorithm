#include <bits/stdc++.h>
using namespace std;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};
int N, a[101][101], visited[101][101], ret = 1;

void DFS(int y, int x, int h){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
        if(a[ny][nx] > h && !visited[ny][nx]) DFS(ny, nx, h);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i < 101; i++){
        fill(&visited[0][0], &visited[0][0] + 101*101, 0);
        int sum = 0;
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                if(a[j][k] > i && !visited[j][k]){
                    DFS(j, k, i);
                    sum++;
                }
            }
        }
        ret = max(ret, sum);
    }

    cout << ret << "\n";

    return 0;
}