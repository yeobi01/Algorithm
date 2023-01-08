#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int dp[61][61][61], a[3], N, visited[64][64][64];
int _a[6][3]{
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 3, 9},
    {1, 9, 3},
};
struct A{ int a, b, c; };
queue<A> q;

int BFS(int a, int b, int c){
    visited[a][b][c] = 0;
    q.push({a, b, c});
    while(q.size()){
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();
        if(visited[0][0][0]) break;
        for(int i = 0; i < 6; i++){
            int na = max(0, a - _a[i][0]);
            int nb = max(0, b - _a[i][1]);
            int nc = max(0, c - _a[i][2]);
            if(visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({na, nb, nc});
        }
    }
    return visited[0][0][0]; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    cout << BFS(a[0], a[1], a[2]) << "\n";

    return 0;
}