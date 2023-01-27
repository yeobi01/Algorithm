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
    cout << "\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << arr[i][j] << " ";
        } cout << "\n";
    }

    return 0;
}