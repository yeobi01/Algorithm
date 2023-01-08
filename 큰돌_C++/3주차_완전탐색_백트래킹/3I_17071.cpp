#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MAX = 500000;

int N, K, ok, turn = 1, x;
int visited[2][MAX + 4];
queue<int> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    if(N == K){ cout << 0 << "\n"; return 0; }

    visited[0][N] = 1;
    q.push(N);
    while(q.size()){
        K += turn;
        if(K > MAX) break;
        if(visited[turn % 2][K]){
            ok = true;
            break;
        }
        int qSize = q.size();
        for(int i = 0; i < qSize; i++){
            x = q.front(); q.pop();
            for(int nx : {x - 1, x + 1, 2 * x}){
                if(nx < 0 || nx > MAX || visited[turn % 2][nx]) continue;
                visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1;
                if(nx == K){ ok = 1; break; }
                q.push(nx);
            }
            if(ok) break;
        }
        if(ok) break;
        turn++;
    }
    if(ok) cout << turn << "\n";
    else cout << -1 << "\n";
    return 0;
}