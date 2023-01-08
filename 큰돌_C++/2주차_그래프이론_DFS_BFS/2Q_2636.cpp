#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int N, M, a[101][101], visited[101][101], y, x, t, ret;
vector<pair<int,int>> v;

void DFS(int y, int x){ 
    visited[y][x] = 1; 
    if(a[y][x] == 1) { 
        v.push_back({y, x}); 
        return; 
    } 
    for(int i = 0; i < 4; i++){ 
        int ny = y + dy[i]; 
        int nx = x + dx[i]; 
        if(ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) continue; 
        DFS(ny, nx); 
    } 
    return; 
}

bool check(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(a[i][j] == 1) return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> a[i][j];
        }
    }

    while(true){
        ret = 0;
        fill(&visited[0][0], &visited[0][0] + 101*101, 0); v.clear();
        DFS(0, 0);
        for(auto x : v){
            ret++;
            a[x.first][x.second] = 0;
        }
        t++;
        if(!check()) break;
    }
    
    cout << t << "\n" << ret << "\n";
    return 0;
}