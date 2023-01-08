#include <bits/stdc++.h>
using namespace std;

const int max_n = 104;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m, a[max_n][max_n], visited[max_n][max_n], y, x;

void BFS(){
    queue<pair<int,int>> q;
    q.push({0, 0});
    visited[0][0] = 1;
    while(!q.empty()){
        tie(y, x) = q.front(); q.pop();

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0) continue;
            if(visited[ny][nx]) continue;  
            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }

    BFS();

    cout << visited[n-1][m-1] << "\n";

    return 0;
}