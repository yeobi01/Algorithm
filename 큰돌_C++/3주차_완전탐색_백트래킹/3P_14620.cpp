#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MAX = 1501;

int N, arr[104][104], visited[104][104], ret = INF;

int price(){
    int sum = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(visited[i][j]) sum += arr[i][j];
        }
    }
    return sum;
}

void go(int here, int cnt){
    if(cnt == 3){
        int temp = price();
        ret = min(ret, temp);
        return;
    }
    for(int i = here; i < N - 1; i++){
        for(int j = 1; j < N - 1; j++){
            if(visited[i][j] || visited[i-1][j] || visited[i+1][j] || visited[i][j-1] || visited[i][j+1]) continue;
            visited[i][j] = 1;
            visited[i-1][j] = 1;
            visited[i+1][j] = 1;
            visited[i][j-1] = 1;
            visited[i][j+1] = 1;
            go(here, cnt + 1);
            visited[i][j] = 0;
            visited[i-1][j] = 0;
            visited[i+1][j] = 0;
            visited[i][j-1] = 0;
            visited[i][j+1] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }

    go(1, 0);
    cout << ret << "\n";
    return 0;
}