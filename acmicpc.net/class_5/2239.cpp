#include<bits/stdc++.h>
using namespace std;   
const int INF = 987654321;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

int arr[9][9];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            char c; cin >> c;
            arr[i][j] = c - 'a';
        }
    }

    

    return 0;
}
