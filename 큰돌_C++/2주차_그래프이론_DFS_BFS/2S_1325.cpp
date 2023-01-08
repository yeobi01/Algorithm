#include <bits/stdc++.h>
using namespace std;

int N, M, dp[100001], visited[100001], max_temp;
vector<int> v[100001];

int DFS(int x){
    visited[x] = 1;
    int ret = 1;
    for(int i = 0; i < v[x].size(); i++){
        if(visited[v[x][i]]) continue;
        ret += DFS(v[x][i]);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        v[b].push_back(a);
    }
    for(int i = 1; i <= N; i++){
        memset(visited, 0, sizeof(visited));
        dp[i] = DFS(i);
        max_temp = max(max_temp, dp[i]);
    }
    for(int i = 1; i <= N; i++){
        if(max_temp == dp[i]) cout << i << " ";
    }
    return 0;
}