#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int N, M, K, ret = INF, arr[51][51], brr[51][51], dir, visited[51][51];
int sy, sx, ey, ex;
vector<pair<int, int>> vv;
vector<int> v_idx;
struct A{
    int y, x, cnt;
};
vector<A> v;

void go(int y, int x, int first){
	if(!first && y == sy && x == sx) dir++; 
	if(!first && y == sy && x == ex) dir++; 
	if(!first && y == ey && x == ex) dir++;
	if(!first && y == ey && x == sx) dir++; 
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(visited[ny][nx]) return;
    vv.push_back({ny, nx});
    go(ny, nx, 0);
}
void rotateAll(int y, int x, int cnt){
    for(int i = 1; i <= cnt; i++){
        sy = y - i;
        sx = x - i;
        ey = y + i;
        ex = x + i;
        vv.clear();
        dir = 0;
        memset(visited, 0, sizeof(visited));
        visited[sy][sx] = 1;
        vv.push_back({sy, sx});
        go(sy, sx, 1);
        vector<int> vvv;
        for(pair<int, int> c : vv) vvv.push_back(brr[c.first][c.second]);
        rotate(vvv.begin(), vvv.begin() + vvv.size() - 1, vvv.end());
        for(int i = 0; i < vv.size(); i++) brr[vv[i].first][vv[i].second] = vvv[i];
    }
}

int solve(){
    for(int i : v_idx) rotateAll(v[i].y, v[i].x, v[i].cnt);
    int _ret = INF;
    for(int i = 0; i < N; i++){
        int cnt = 0;
        for(int j = 0; j < M; j++) cnt += brr[i][j];
        _ret = min(_ret, cnt);
    }
    return _ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < K; i++){
        int r, c, s;
        cin >> r >> c >> s; r--; c--;
        v.push_back({r, c, s});
        v_idx.push_back(i);
    }
    do{
        memcpy(brr, arr, sizeof(brr));
        ret = min(ret, solve());
    }while(next_permutation(v_idx.begin(), v_idx.end()));
    cout << ret << "\n";
    return 0;
}