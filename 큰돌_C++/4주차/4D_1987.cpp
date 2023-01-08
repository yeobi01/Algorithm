#include<bits/stdc++.h>
using namespace std;   
const int INF = 987654321;
const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {1, -1, 0, 0};

int R, C, ret;
char arr[21][21];

void DFS(int y, int x, int num, int depth){
    ret = max(ret, depth);
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        int _next = (1 << (int)(arr[ny][nx] - 'A'));
        if((num & _next) == 0) DFS(ny, nx, num | _next, depth + 1);
    }
    return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> arr[i][j];
        }
    }
    DFS(0, 0, 1 << (int)(arr[0][0] - 'A'), 1);
    cout << ret << "\n";
    return 0;
}