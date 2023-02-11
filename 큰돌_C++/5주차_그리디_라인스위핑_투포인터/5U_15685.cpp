#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};

vector<int> dragon[4][11];
int cnt, n, x, y, d, g, arr[101][101];

void go(int x, int y, int d, int g){
    int _x = x;
    int _y = y;
    arr[_x][_y] = 1;
    for(int i = 0; i <= g; i++){
        for(int dir : dragon[d][i]){
            _x += dx[dir];
            _y += dy[dir];
            arr[_x][_y] = 1;
        }
    }
    return;
}

void makeDragon(){
    for(int i = 0; i < 4; i++){
        dragon[i][0].push_back(i);
        dragon[i][1].push_back((i + 1) % 4);
        for(int j = 2; j <= 10; j++){
            int _n = dragon[i][j - 1].size();
            for(int k = _n - 1; k >= 0; k--){
                dragon[i][j].push_back((dragon[i][j - 1][k] + 1) % 4);
            }
            for(int k = 0; k < _n; k++){
                dragon[i][j].push_back(dragon[i][j - 1][k]);
            }
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    makeDragon();
    for(int i = 0; i < n; i++){
        cin >> x >> y >> d >> g;
        go(x, y, d, g);
    }
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            if(arr[i][j] && arr[i + 1][j] && arr[i + 1][j + 1] && arr[i][j + 1]) cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}