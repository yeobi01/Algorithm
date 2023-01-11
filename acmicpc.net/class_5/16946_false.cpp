#include<bits/stdc++.h>
using namespace std;   
const int INF = 987654321;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

int N, M, arr[1001][1001], visited[1001][1001], comp[1001][1001], ret[1001][1001];
queue<pair<int, int>> q;

int DFS(int y, int x){
    q.push({y, x});
    int sum = 1;
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) continue;
        if(arr[ny][nx]) continue; 
        sum += DFS(ny, nx);
    }
    return sum;
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
                int temp = DFS(i, j);
                while(q.size()){
                    int y, x; tie(y, x) = q.front(); q.pop();
                    comp[y][x] = temp;
                }
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(arr[i][j]){
                int sum = 1;
                for(int k = 0; k < 4; k++){
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                    sum += comp[ny][nx];
                }
                ret[i][j] = sum;
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << ret[i][j] % 10;
        } cout << "\n";
    }

    return 0;
}