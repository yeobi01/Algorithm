#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int N, arr[21][21], visited[21], ret = INF;

void diff(){
    int sum_t = 0, sum_f = 0;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(visited[i] && visited[j]) sum_t += (arr[i][j] + arr[j][i]);
            else if(!visited[i] && !visited[j]) sum_f += (arr[i][j] + arr[j][i]);
        }
    }
    ret = min(ret, abs(sum_t - sum_f));
    return;
}

void go(int cnt, int now){
    if(now > N) return;
    if(cnt == N/2){
        diff();
        return;
    }

    visited[now] = 1;
    go(cnt + 1, now + 1);
    visited[now] = 0;
    go(cnt, now + 1);
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

    visited[0] = 1;
    go(1, 1);

    cout << ret << "\n";
    return 0;
}