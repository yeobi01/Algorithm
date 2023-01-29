#include<bits/stdc++.h>
using namespace std;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int N, K, l, y, x, ret, dir = 1;
int arr[104][104], visited[104][104];
deque<pair<int,int>> dq;
queue<pair<int,int>> _time;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for(int i = 0; i < K; i++){
        cin >> y >> x;
        arr[--y][--x] = 1;
    }
    cin >> l;
    for(int i = 0; i < l; i++){
        int t; char c;
        cin >> t >> c;
        if(c == 'D') _time.push({t, 1});
        else _time.push({t, 3});
    }
    visited[0][0] = 1;
    dq.push_back({0, 0});
    while(dq.size()){
        ret++;
        tie(y, x) = dq.front();
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny >= N || ny < 0 || nx >= N || nx < 0 || visited[ny][nx]) break;

        if(!arr[ny][nx]){
            visited[dq.back().first][dq.back().second] = 0;
            dq.pop_back();
        } else arr[ny][nx] = 0;

        visited[ny][nx] = 1;
        dq.push_front({ny, nx});
        if(ret == _time.front().first){
            dir = (dir + _time.front().second) % 4;
            _time.pop();
        }
    }
    cout << ret << "\n";
    return 0;
}