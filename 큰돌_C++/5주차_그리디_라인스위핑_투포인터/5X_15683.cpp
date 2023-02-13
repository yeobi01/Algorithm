#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};

int N, M, arr[9][9], ret = INF;
vector<pair<int, int>> cctv;

vector<pair<int, int>> go(int y, int x, int dir){
    vector<pair<int, int>> change;
    while(true){
        int ny = y + dy[dir]; 
        int nx = x + dx[dir]; 
        if(ny >= 0 && ny < N && nx >= 0 && nx < M && arr[ny][nx] != 6){
            if(arr[ny][nx] == 0){
                arr[ny][nx] = 8; 
                change.push_back({ny, nx});
            }
            y = ny; 
            x = nx; 
        } else break;
    }
    return change;
}

vector<pair<int, int>> extendCCTV(int here, int dir){
    vector<pair<int, int>> _change; 
    int y = cctv[here].first; 
    int x = cctv[here].second; 
    if(arr[y][x] == 1){
        _change = go(y, x, dir);
    }else if(arr[y][x] == 2){
        for(int i = 0; i <= 2; i +=2){
            vector<pair<int, int>> temp;
            temp = go(y, x, (dir + i) % 4);
            for(auto t : temp) _change.push_back(t);
        }
    }else if(arr[y][x] == 3){
        for(int i = 0; i < 2; i++){
            vector<pair<int, int>> temp;
            temp = go(y, x, (dir + i) % 4);
            for(auto t : temp) _change.push_back(t);
        }
    }else if(arr[y][x] == 4){
        for(int i = 0; i < 3; i++){
            vector<pair<int, int>> temp;
            temp = go(y, x, (dir + i) % 4);
            for(auto t : temp) _change.push_back(t);
        }
    }else if(arr[y][x] == 5){
        for(int i = 0; i < 4; i++){
            vector<pair<int, int>> temp;
            temp = go(y, x, (dir + i) % 4);
            for(auto t : temp) _change.push_back(t);
        }
    }
    return _change; 
}

void dfs(int here){
    if(here == cctv.size()){
        int cnt = 0; 
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(arr[i][j] == 0)cnt++;
            }
        }
        ret = min(cnt, ret);
        return;
    }
    for(int k = 0; k < 4; k++){
        vector<pair<int, int>> _change = extendCCTV(here, k); 
        dfs(here + 1); 
        for(auto b : _change) arr[b.first][b.second] = 0; 
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
            if(0 < arr[i][j] && arr[i][j] < 6) cctv.push_back({i, j});
        }
    }
    dfs(0);
    cout << ret << "\n";
    return 0;
}