#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {1, -1, 0, 0};

int N, M, T, arr[51][51], air_y1, air_y2;
vector<pair<int, pair<int, int>>> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> T;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
            if(!air_y2 && arr[i][j] == -1){
                air_y1 = i;
                air_y2 = i + 1;
            }
        }
    }

    while(T--){
        v.clear();
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(arr[i][j] > 0) v.push_back({arr[i][j], {i, j}});
            }
        }
        for(auto temp : v){
            int amount = temp.first;
            int y = temp.second.first;
            int x = temp.second.second;
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                if(nx == 0 && (ny == air_y1 || ny == air_y2)) continue;
                arr[ny][nx] += amount/5;
                arr[y][x] -= amount/5;
            }
        }

        for(int i = air_y1 - 1; i > 0; i--){
            arr[i][0] = arr[i - 1][0];
        }
        for(int i = 0; i < M - 1; i++){
            arr[0][i] = arr[0][i + 1];
        }
        for(int i = 0; i < air_y1; i++){
            arr[i][M - 1] = arr[i + 1][M - 1];
        }
        for(int i = M - 1; i > 1; i--){
            arr[air_y1][i] = arr[air_y1][i - 1];
        } arr[air_y1][1] = 0;

        for(int i = air_y2 + 1; i < N - 1; i++){
            arr[i][0] = arr[i + 1][0];
        }
        for(int i = 0; i < M - 1; i++){
            arr[N - 1][i] = arr[N - 1][i + 1];
        }
        for(int i = N - 1; i > air_y2; i--){
            arr[i][M - 1] = arr[i - 1][M - 1];
        }
        for(int i = M - 1; i > 1; i--){
            arr[air_y2][i] = arr[air_y2][i - 1];
        } arr[air_y2][1] = 0;
    }

    int ret = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(arr[i][j] > 0) ret += arr[i][j];
        }
    }
    cout << ret << "\n";
    return 0;
}