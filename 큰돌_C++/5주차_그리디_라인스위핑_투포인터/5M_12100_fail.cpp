#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

long long N, arr[6][21][21], ret;

void _max(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            ret = max(ret, arr[5][i][j]);
        }
    }
    return;
}

void go(int cnt){
    if(cnt == 5){
        _max();
        return;
    }

    for(int t = 0; t < 4; t++){
        if(t == 0){ // 오른쪽
            for(int i = 0; i < N; i++){
                int k = N - 1;
                for(int j = N - 1; j >= 0; j--){
                    if(arr[cnt][i][j] == 0) continue;
                    if(j == 0){
                        arr[cnt + 1][i][k] = arr[cnt][i][j];
                        k--;
                        continue;
                    }
                    if(arr[cnt][i][j] == arr[cnt][i][j - 1]){
                        arr[cnt + 1][i][k] = arr[cnt][i][j] * 2;
                        j--; k--;
                    } else{
                        arr[cnt + 1][i][k] = arr[cnt][i][j];
                        k--;
                    }
                }
                for(; k >= 0; k--) arr[cnt + 1][i][k] = 0;
            }
        } else if(t == 1){ // 왼쪽
            for(int i = 0; i < N; i++){
                int k = 0;
                for(int j = 0; j < N; j++){
                    if(arr[cnt][i][j] == 0) continue;
                    if(j == N - 1){
                        arr[cnt + 1][i][k] = arr[cnt][i][j];
                        k++;
                        continue;
                    }
                    if(arr[cnt][i][j] == arr[cnt][i][j + 1]){
                        arr[cnt + 1][i][k] = arr[cnt][i][j] * 2;
                        j++; k++;
                    } else{
                        arr[cnt + 1][i][k] = arr[cnt][i][j];
                        k++;
                    }
                }
                for(; k < N; k++) arr[cnt + 1][i][k] = 0;
            }
        } else if(t == 2){ // 위쪽
            for(int j = 0; j < N; j++){
                int k = 0;
                for(int i = 0; i < N; i++){
                    if(arr[cnt][i][j] == 0) continue;
                    if(i == N - 1){
                        arr[cnt + 1][k][j] = arr[cnt][i][j];
                        k++;
                        continue;
                    }
                    if(arr[cnt][i][j] == arr[cnt][i + 1][j]){
                        arr[cnt + 1][k][j] = arr[cnt][i][j] * 2;
                        i++; k++;
                    } else{
                        arr[cnt + 1][k][j] = arr[cnt][i][j];
                        k++;
                    }
                }
                for(; k < N; k++) arr[cnt + 1][k][j] = 0;
            }
        } else if(t == 3){ // 아래쪽
            for(int j = 0; j < N; j++){
                int k = N - 1;
                for(int i = N - 1; i >= 0; i--){
                    if(arr[cnt][i][j] == 0) continue;
                    if(i == 0){
                        arr[cnt + 1][k][j] = arr[cnt][i][j];
                        k--;
                        continue;
                    }
                    if(arr[cnt][i][j] == arr[cnt][i - 1][j]){
                        arr[cnt + 1][k][j] = arr[cnt][i][j] * 2;
                        i--, k--;
                    } else{
                        arr[cnt + 1][k][j] = arr[cnt][i][j];
                        k--;
                    }
                }
                for(; k >= 0; k--) arr[cnt + 1][k][j] = 0;
            }
        }
        go(cnt + 1);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N;j ++){
            cin >> arr[0][i][j];
        }
    }

    go(0);
    /*
    int cnt = 0;
    for(int j = 0; j < N; j++){
        int k = 0;
        for(int i = 0; i < N; i++){
            if(arr[cnt][i][j] == 0) continue;
            if(arr[cnt][i][j] == arr[cnt][i + 1][j]){
                arr[cnt + 1][k][j] = arr[cnt][i][j] * 2;
                i++; k++;
            } else{
                arr[cnt + 1][k][j] = arr[cnt][i][j];
                k++;
            }
        }
        for(; k < N; k++) arr[cnt + 1][k][j] = 0;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) {
            cout << arr[cnt + 1][i][j] << " "; 
        } cout << "\n";
    }*/

    cout << ret << "\n";

    return 0;
}