#include<bits/stdc++.h>
using namespace std;   
const int INF = 987654321;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

int N, M, cnt, mx, big, arr[51][51], visited[51][51], comSize[2501];

int DFS(int y, int x){
    int ret = 1;
    for(int i = 0; i < 4; i++){
        if((arr[y][x] & (1 << i))) continue;

        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) continue;

        visited[ny][nx] = cnt;
        ret += DFS(ny, nx);
    }
    return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> M >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!visited[i][j]){
                cnt++;
                visited[i][j] = cnt;
                comSize[cnt] = DFS(i, j);
                mx = max(mx, comSize[cnt]);
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(i + 1 < N){
                int a = visited[i + 1][j];
                int b = visited[i][j];
                if(a != b) big = max(big, comSize[a] + comSize[b]);
            }
            if(j + 1 < M){
                int a = visited[i][j + 1];
                int b = visited[i][j];
                if(a != b) big = max(big, comSize[a] + comSize[b]);
            }
        }
    }
    cout << cnt << "\n" << mx << "\n" << big << "\n";
    return 0;
}