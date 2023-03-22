#include<bits/stdc++.h>
using namespace std;   
typedef long long ll;
const int INF = 987654321;

int T, N, M;
char a[21][21], b[21][21], ret[21][21];

void input(){
    fill(&a[0][0], &a[0][0] + 21 * 21, '.');
    fill(&b[0][0], &b[0][0] + 21 * 21, '.');
    fill(&ret[0][0], &ret[0][0] + 21 * 21, '.');

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> a[i][j];
        }
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            cin >> b[i][j];
        }
    }
}

void rotate(){
    int temp[21][21]; fill(&temp[0][0], &temp[0][0] + 21 * 21, '.');
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            temp[i][j] = b[M - j - 1][i];
        }
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            b[i][j] = temp[i][j];
        }
    }
}

bool check(int y, int x){
    for(int i = y; i < y + M; i++){
        for(int j = x; j < x + M; j++){
            if(a[i][j] == '.' && b[i - y][j - x] == '*') return false;
        }
    }
    return true;
}

void stamp(int y, int x){
    for(int i = y; i < y + M; i++){
        for(int j = x; j < x + M; j++){
            if(b[i - y][j - x] == '*'){
                ret[i][j] = '*';
            }
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    while(T--){
        input();
        
        for(int t = 0; t < 4; t++){
            for(int i = 0; i < N - M + 1; i++){
                for(int j = 0; j < N - M + 1; j++){
                    if(check(i, j)){
                        stamp(i, j);
                    }
                }
            }
            rotate();
        }

        bool flag = true;
        for(int i = 0; i < N && flag; i++){
            for(int j = 0; j < N && flag; j++){
                if(ret[i][j] != a[i][j]){
                    flag = false;
                }
            }
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
} 