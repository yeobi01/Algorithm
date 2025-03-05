// 1277번. 발전소 설치

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 987654321;

int N, W;
vector<pair<int, int>> v;
double connect[1000][1000];
double dist[1000];
bool visited[1000];
double line_length_max;

int get_min_index(){
    double _min = INF;
    int _min_idx = 0;
    for(int i = 0; i < N; i++){
        if(visited[i]) continue;
        if(_min > dist[i]){
            _min = dist[i];
            _min_idx = i;
        }
    }
    // if(_min_idx != -1) visited[_min_idx] = true;
    return _min_idx;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> W;
    cin >> line_length_max;
    for(int i = 0; i < N; i++){
        int x; int y; cin >> x >> y;
        v.push_back({x, y});
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            double x = v[i].first - v[j].first;
            double y = v[i].second - v[j].second;
            double length = sqrt(x*x + y*y);
            if(length <= line_length_max){
                connect[i][j] = length;
            } else{
                connect[i][j] = INF;
            }
        }
    }
    
    for(int i = 0; i < W; i++){
        int a; int b; cin >> a >> b;
        connect[a-1][b-1] = 0;
        connect[b-1][a-1] = 0;
    }

    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < N; j++){
    //         cout << connect[i][j] << " ";
    //     } cout << "\n";
    // }

    for(int i = 0; i < N; i++) dist[i] = connect[0][i];
    visited[0] = true;
    for(int i = 0; i < N - 2; i++){
        int cur = get_min_index();
        visited[cur] = true;
        
        // if(i == -1) break;
        for(int j = 0; j < N; j++){
            if(visited[j]) continue;
            if(dist[j] > dist[cur] + connect[cur][j]){
                dist[j] = dist[cur] + connect[cur][j];
            }
        }
    }
    // for(int i = 0; i < N; i++){
    //     cout << dist[i] << " ";
    // }
    int res = dist[N - 1] * 1000;
    cout << res << "\n";

    return 0;
}