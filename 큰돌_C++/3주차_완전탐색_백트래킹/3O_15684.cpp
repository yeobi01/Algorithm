#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MAX = 1501;

int N, M, H, arr[34][34], ret = INF;
bool check(){
    for(int i = 1; i <= N; i++){
        int start = i;
        for(int j = 1; j <= H; j++){
            if(arr[j][start]) start++;
            else if(arr[j][start - 1]) start--;
        }
        if(start != i) return false;
    }
    return true;
}
void go(int here, int cnt){
    if(cnt > 3 || cnt >= ret) return;
    if(check()){
        ret = min(ret, cnt);
        return;
    }
    for(int i = here; i <= H; i++){
        for(int j = 1; j <= N; j++){
            if(arr[i][j] || arr[i][j-1] || arr[i][j+1]) continue;
            arr[i][j] = 1;
            go(i, cnt + 1);
            arr[i][j] = 0;
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> H;
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        arr[a][b] = 1;
    }
    go(1, 0);
    cout << ((ret != INF) ? ret : -1) << "\n";
    return 0;
}