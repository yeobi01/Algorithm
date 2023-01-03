#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int N, M, ret, a[10][10], visited[10][10];
vector<pair<int,int>> virusList, wallList;

void DFS(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if(a[ny][nx] == 0 && !visited[ny][nx]) DFS(ny, nx);
    }
    return;
}

int solve(){
    fill(&visited[0][0], &visited[0][0] + 100, 0);
    for(pair<int,int> p : virusList){
        DFS(p.first, p.second);
    }

    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(a[i][j] == 0 && !visited[i][j]) cnt++;
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> a[i][j];
            if(a[i][j] == 2) virusList.push_back({i, j});
            if(a[i][j] == 0) wallList.push_back({i, j});
        }
    }
    
    for(int i = 0; i < wallList.size(); i++){
        for(int j = 0; j < i; j++){
            for(int k = 0; k < j; k++){
                a[wallList[i].first][wallList[i].second] = 1;
                a[wallList[j].first][wallList[j].second] = 1;
                a[wallList[k].first][wallList[k].second] = 1;
                ret = max(ret, solve());
                a[wallList[i].first][wallList[i].second] = 0;
                a[wallList[j].first][wallList[j].second] = 0;
                a[wallList[k].first][wallList[k].second] = 0;
            }
        }
    }

    cout << ret << "\n";

    return 0;
}