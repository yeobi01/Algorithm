#include <bits/stdc++.h>
using namespace std;
const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};

int T, R, C, ret, visited[27];
char arr[21][21];

void DFS(int y, int x, int cnt){
    ret = max(ret, cnt);

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited[arr[ny][nx] - 'A']) continue;
        visited[arr[ny][nx] - 'A'] = 1;
        DFS(ny, nx, cnt + 1);
        visited[arr[ny][nx] - 'A'] = 0;
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int t = 1; t <= T; t++){
        fill(&visited[0], &visited[0] + 26, 0); ret = 0;

        cin >> R >> C;
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                cin >> arr[i][j];
            }
        }

        visited[arr[0][0] - 'A'] = 1;
        DFS(0, 0, 1);

        cout << "#" << t << " " << ret << "\n";
    }
}
/*
3
2 4
CAAB
ADCB
3 6
HFDFFB
AJHGDH
DGAGEH
5 5
IEFCJ
FHFKC
FFALF
HFGCF
HMCHH

1
2 4
CAAB
ADCB
*/