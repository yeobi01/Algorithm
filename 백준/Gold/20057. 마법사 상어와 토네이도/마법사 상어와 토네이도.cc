// 20057번. 마법사 상어와 토네이도

#include <bits/stdc++.h>
using namespace std;

int n, arr[500][500];
int res;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

struct sand{
    int y;
    int x;
    double weight;
};

void move(int y, int x, int d){
    vector<sand> v;
    v.push_back({y + 2*dy[(d + 1)%4], x + 2*dx[(d + 1)%4], 0.02});
    v.push_back({y + 2*dy[(d + 3)%4], x + 2*dx[(d + 3)%4], 0.02});
    v.push_back({y + dy[(d + 1)%4], x + dx[(d + 1)%4], 0.07});
    v.push_back({y + dy[(d + 3)%4], x + dx[(d + 3)%4], 0.07}); 
    v.push_back({y + dy[(d + 1)%4] + dy[(d + 2)%4], x + dx[(d + 1)%4] + dx[(d + 2)%4], 0.01});
    v.push_back({y + dy[(d + 3)%4] + dy[(d + 2)%4], x + dx[(d + 3)%4] + dx[(d + 2)%4], 0.01}); //
    v.push_back({y + dy[(d + 1)%4] + dy[(d)%4], x + dx[(d + 1)%4] + dx[(d)%4], 0.1});
    v.push_back({y + dy[(d + 3)%4] + dy[(d)%4], x + dx[(d + 3)%4] + dx[(d)%4], 0.1});
    v.push_back({y + 2*dy[(d)%4], x + 2*dx[(d)%4], 0.05});
    v.push_back({y + dy[(d)%4], x + dx[(d)%4], 1});

    int total_sand = arr[y][x];
    for(sand sand : v){    
        if(sand.y < 0 || sand.y >= n || sand.x < 0 || sand.x >= n){
            if(sand.weight == 1) res += total_sand;
            else {
                res += (int)(arr[y][x] * sand.weight);
                total_sand -= (int)(arr[y][x] * sand.weight);
            }
            continue;
        }
        if(sand.weight == 1) arr[sand.y][sand.x] += total_sand;
        else {
            arr[sand.y][sand.x] += (int)(arr[y][x] * sand.weight);
            total_sand -= (int)(arr[y][x] * sand.weight);
        }
    }

    arr[y][x] = 0;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    int y = n/2, x = n/2, loop_cnt = 1, cnt = 0, d = 3;
    while(1){
        for(int i = 0; i < loop_cnt; i++){
            move(y + dy[d], x + dx[d], d);
            y += dy[d]; x += dx[d];
        }
        d = (d + 3) % 4;
        cnt++;
        if(cnt == 2){
            loop_cnt++;
            if(loop_cnt == n) loop_cnt--;
            cnt = 0;
        }
        if(y == 0 && x == 0) {
            break;
        }
    }
    
    cout << res << "\n";
    return 0;
}
