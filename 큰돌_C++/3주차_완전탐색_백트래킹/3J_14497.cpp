#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MAX = 300;

const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};

int N, M, a[MAX + 4][MAX + 4], visited[MAX + 4][MAX + 4], ret; 
int y_1, x_1, y_2, x_2;
bool flag = false;

void DFS(int y, int x){
    if(y == y_2 && x == x_2) flag = true;

    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) continue;
        if(a[ny][nx] == 0){
            DFS(ny, nx);
        } else if(a[ny][nx] == 1){
            a[ny][nx] = 0;
            visited[ny][nx] = 1;
        }
    }
    return;
}

void print(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << a[i][j] << " "; 
        }
        cout << "\n";
    }
    cout << "\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin >> y_1 >> x_1 >> y_2 >> x_2;
    y_1--; x_1--; y_2--; x_2--;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            char c; cin >> c;
            if(c == '#') a[i][j] = 0;
            else if(c == '*') a[i][j] = 0;
            else a[i][j] = c - '0';
        }
    }

    for(ret = 0; !flag; ret++){
        fill(&visited[0][0], &visited[0][0] + (MAX+4)*(MAX+4), 0);
        DFS(y_1, x_1);
        // print();
    }

    cout << ret << "\n";

    return 0;
}