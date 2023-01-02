#include <bits/stdc++.h>
using namespace std;

int H, W, a[101][101], y, x;
queue<pair<int, int>> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&a[0][0], &a[0][0] + 101*101, -1);
    cin >> H >> W;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            char c; cin >> c;
            if(c == 'c'){ q.push({i, j}); a[i][j] = 0;}
        }
    }
    while(!q.empty()){
        tie(y, x) = q.front(); q.pop();
        int ny = y;
        int nx = x + 1;
        if(nx > W) continue;
        if(a[ny][nx] != -1) a[ny][nx] = min(a[ny][nx], a[y][x] + 1);
        else a[ny][nx] = a[y][x] + 1;
        q.push({ny, nx});
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
/*
int main () {
	cin >> H >> W; 
	for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            char c; cin >> c;
            if(c == '.') a[i][j] = -1;
            else a[i][j] = 0;
        }
	}
	for(int i = 0; i < H; i++){ 
		for(int j = 0; j < W; j++){
			if(a[i][j] == 0){ 
				int cnt = 1;
				while(a[i][j + 1] == -1){
					a[i][j + 1] = cnt++;
					j++;
				} 
			}
		} 
	} 
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++) cout << a[i][j] << " ";
		cout << "\n";
	} 
	return 0;
}
*/