#include <bits/stdc++.h>
using namespace std;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};
int M, N, K, a[101][101], visited[101][101];
vector<int> v;

int_least16_t DFS(int y, int x){
    visited[y][x] = 1;
    int ret = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= M || nx < 0 || nx >= N || visited[ny][nx]) continue;
        if(!a[ny][nx]) ret += DFS(ny, nx);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> K;
    for(int i = 0; i < K; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = y1; i < y2; i++){
            for(int j = x1; j < x2; j++){
                a[i][j] = 1;
            }
        }
    }
    
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(a[i][j] == 0 && !visited[i][j]){
                v.push_back(DFS(i, j));
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for(auto x : v) cout << x << " ";
    return 0;
}