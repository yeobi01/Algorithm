#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};

char a[1004][1004];
int N, M, y, x, ret, jy, jx;
int fire_check[1004][1004], person_check[1004][1004];
    queue<pair<int, int>> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&fire_check[0][0], &fire_check[0][0] + 1004*1004, INF);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> a[i][j];
            if(a[i][j] == 'F'){
                fire_check[i][j] = 1;
                q.push({i, j});
            } else if(a[i][j] == 'J'){
                jy = i; jx = j;
            }
        }
    }

    while(q.size()){
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(fire_check[ny][nx] != INF || a[ny][nx] == '#') continue;
            fire_check[ny][nx] = fire_check[y][x] + 1;
            q.push({ny, nx});
        }
    }
    
    person_check[jy][jx] = 1;
    q.push({jy, jx});
    while(q.size()){
        tie(y, x) = q.front(); q.pop();
        if(y == N - 1 || x == M - 1 || y == 0 || x == 0){
            ret = person_check[y][x];
            break;
        }
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(person_check[ny][nx] || a[ny][nx] == '#') continue;
            if(fire_check[ny][nx] <= person_check[y][x] + 1) continue;
            person_check[ny][nx] = person_check[y][x] + 1;
            q.push({ny, nx});
        }
    }

    if(ret != 0) cout << ret << "\n";
    else cout << "IMPOSSIBLE \n";
    return 0;
}