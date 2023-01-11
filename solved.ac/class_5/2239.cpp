#include<bits/stdc++.h>
using namespace std;   
const int INF = 987654321;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

int arr[9][9], row[9][10], col[9][10], square[9][10], flag;

void print(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << arr[i][j];
        } cout << "\n";
    }
}

void go(int idx){
    if(flag) return;
    if(idx > 80){
        flag = true; print();
        return;
    }
    int y = idx / 9;
    int x = idx % 9;
    int square_num = (y / 3) * 3 + x / 3;
    if(arr[y][x] == 0){
        for(int i = 1; i <= 9; i++){
            if(!row[y][i] && !col[x][i] && !square[square_num][i]){
                arr[y][x] = i;
                row[y][i] = 1;
                col[x][i] = 1;
                square[square_num][i] = 1;
                go(idx + 1);
                arr[y][x] = 0;
                row[y][i] = 0;
                col[x][i] = 0;
                square[square_num][i] = 0;
            }
        }
    } else go(idx + 1);
    return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            char c; cin >> c;
            arr[i][j] = (int)(c - '0');
            row[i][arr[i][j]] = 1;
            col[j][arr[i][j]] = 1;
            square[(i / 3) * 3 + j / 3][arr[i][j]] = 1;
        }
    }
    go(0);
    return 0;
}
