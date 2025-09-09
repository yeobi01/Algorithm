#include<cstring>
#include <iostream>
#include <vector> 
#include <queue>
using namespace std;

// 1 상 2 오 3 하 4 왼 
int dy[5] = {0, -1, 0, 1, 0};
int dx[5] = {0, 0, 1, 0, -1};

int N, K, R;
int arr[100][100]; // 5 소 
int res = 0;

void bfs(int y, int x){
     int visited[100][100];
     int temp_map[100][100];
     memset(visited, 0, sizeof(visited));
     memset(temp_map, 0, sizeof(visited));
     
     for(int i = 0; i < N; i++){
             for(int j = 0; j < N; j++){
                     temp_map[i][j] = arr[i][j];
             }
     }
     
     int notfound_cow_count = K - 1;
     
     queue<pair<int,int>> q;
     q.push({y, x});
     visited[y][x] = 1;
     while(!q.empty()){
           pair<int,int> p = q.front();
           q.pop();
           int cur_y = p.first;
           int cur_x = p.second;
           
           for(int i = 1; i < 5; i++){
                   if(temp_map[cur_y][cur_x] & (1 << i)) continue;
                   
                   int ny = cur_y + dy[i];
                   int nx = cur_x + dx[i];
                   if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                   if(visited[ny][nx]) continue;
                   
                   q.push({ny, nx});
                   visited[ny][nx] = 1;
                   if(temp_map[ny][nx] & (1 << 5)) {
                        notfound_cow_count--;
                }
           }
     }
     
     res += notfound_cow_count;
}

int main(){
    cin >> N >> K >> R;
    for(int i = 0; i < R; i++){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--; x1--; y2--; x2--;

        int diff_y = y2 - y1;
        int diff_x = x2 - x1;
        
        if(diff_y == -1 && diff_x == 0){
                arr[y1][x1] |= 1 << 1;
                arr[y2][x2] |= 1 << 3;
        } else if(diff_y == 0 && diff_x == 1){
                arr[y1][x1] |= 1 << 2;
                arr[y2][x2] |= 1 << 4;
        } else if(diff_y == 1 && diff_x == 0){
                arr[y1][x1] |= 1 << 3;
                arr[y2][x2] |= 1 << 1;
        } else if(diff_y == 0 && diff_x == -1){
                arr[y1][x1] |= 1 << 4;
                arr[y2][x2] |= 1 << 2;
        }
    }

    vector<pair<int,int>> v;
    for(int i = 0; i < K; i++){
        int y, x;
        cin >> y >> x;
        y--; x--;

        arr[y][x] |= 1 << 5;
        v.push_back({y, x});       
    }
    for(auto a : v){
        bfs(a.first, a.second); 
    }
    
    cout << res / 2 << endl;
}
