#include<bits/stdc++.h>
using namespace std;   
const int INF = 987654321;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

int N, M, arr[1001][1001], visited[1001][1001];

void BFS(int y, int x){
    queue<pair<int, int>> q;
    vector<pair<int, int>> wall;
    int cnt = 1; q.push({y, x}); visited[y][x] = 1;
    while(!q.empty()){
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) continue;
            if(arr[ny][nx] == 0){
                visited[ny][nx] = 1;
                q.push({ny, nx});
                cnt++;
            } else {
                visited[ny][nx] = 1;
                wall.push_back({ny, nx});
            }
        }
    }
    for(pair<int, int> p : wall){
        arr[p.first][p.second] += cnt;
        visited[p.first][p.second] = 0;
    }
    return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            char c; cin >> c;
            arr[i][j] = (int)(c - '0');
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!arr[i][j] && !visited[i][j]){
                BFS(i, j);
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << arr[i][j] % 10;
        } cout << "\n";
    }

    return 0;
}