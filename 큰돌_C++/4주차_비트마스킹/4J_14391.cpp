#include<bits/stdc++.h>
using namespace std;   
const int INF = 987654321;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

int N, M, arr[4][4], ret;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            char c; cin >> c;
            arr[i][j] = c - '0';
        }
    }
    for(int t = 0; t < (1 << N*M); t++){
        int sum = 0;
        for(int i = 0; i < N; i++){
            int temp = 0;
            for(int j = 0; j < M; j++){
                int idx = i * M + j;
                if((t & (1 << idx)) == 0) temp = temp * 10 + arr[i][j];
                else { sum += temp; temp = 0; }
            }
            if(temp != 0) sum += temp;
        }
        for(int j = 0; j < M; j++){
            int temp = 0;
            for(int i = 0; i < N; i++){
                int idx = i * M + j;
                if(t & (1 << idx)) temp = temp * 10 + arr[i][j];
                else { sum += temp; temp = 0; }
            }
            if(temp != 0) sum += temp;
        }
        ret = max(ret, sum);
    }
    cout << ret << "\n";
    return 0;
}