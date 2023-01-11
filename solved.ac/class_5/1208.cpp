#include<bits/stdc++.h>
using namespace std;   
const int MAX = 987654321;
const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};
//                 U  D  L  R
char arr[1001][1001];
int visited[1001][1001];
int N, M, ret;

void DFS(int y, int x){
    visited[y][x] = 1;

    int i;
    if(arr[y][x] == 'U') i = 0;
    else if(arr[y][x] == 'D') i = 1;
    else if(arr[y][x] == 'L') i = 2;
    else if(arr[y][x] == 'R') i = 3;

    int ny = y + dy[i];
    int nx = x + dx[i];
    if(visited[ny][nx] == 1) ret++;
    if(visited[ny][nx] == 0) DFS(ny, nx);
    visited[y][x] = 2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!visited[i][j]){
                DFS(i, j);
            }
        }
    }
    
    cout << ret << "\n";
    return 0;
} // 유니온파인드로도 풀이 가능..