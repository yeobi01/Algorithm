#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MAX = 200000;

int N, K, x;
int visited[MAX], back[MAX];
queue<int> q;
vector<int> ret;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    visited[N] = 1;
    q.push(N);
    while(!q.empty()){
        x = q.front(); q.pop();
        for(int nx : {x - 1, x + 1, x * 2}){
            if(nx < 0 || nx >= MAX || visited[nx]) continue;
            visited[nx] = visited[x] + 1;
            back[nx] = x;
            q.push(nx);
        }
    }

    ret.push_back(K);
    for(int i = K; i != N; i = back[i]){
        ret.push_back(back[i]);
    }

    cout << visited[K] - 1 << "\n";
    for(int i = ret.size() - 1; i >= 0; i--){
        cout << ret[i] << " ";
    }

    return 0;
}