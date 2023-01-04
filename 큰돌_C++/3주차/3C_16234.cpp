#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};

int N, L, R, cnt, sum, a[51][51], visited[51][51];
vector<pair<int,int>> v;

void DFS(int y, int x){
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx]) continue;
        if(abs(a[ny][nx] - a[y][x]) >= L && abs(a[ny][nx] - a[y][x]) <= R){
            visited[ny][nx] = 1;
            v.push_back({ny, nx});
            sum += a[ny][nx];
            DFS(ny, nx);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L >> R;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> a[i][j];
        }
    }

    while(true){
        bool flag = 0;
        fill(&visited[0][0], &visited[0][0] + 51*51, 0);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(!visited[i][j]){
                    v.clear();
                    visited[i][j] = 1;
                    v.push_back({i, j});
                    sum = a[i][j];
                    DFS(i, j);
                    if(v.size() == 1) continue;
                    for(pair<int,int> t : v){
                        a[t.first][t.second] = sum / v.size();
                        flag = 1;
                    }
                }
            }
        }
        if(!flag) break;
        cnt++;
    }
    cout << cnt << "\n";
    
    return 0;
}