#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int N, M, ret, visited[51][51];
char m[51][51];

void BFS(int y, int x){
    fill(&visited[0][0], &visited[0][0] + 51*51, 0);
    visited[y][x] = 1;
    queue<pair<int,int>> q;
    q.push({y, x});
    while(!q.empty()){
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || m[ny][nx] == 'W') continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
            ret = max(ret, visited[ny][nx]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> m[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(m[i][j] == 'L') BFS(i, j);
        }
    }

    cout << ret - 1 << "\n";

    return 0;
}