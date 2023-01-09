#include<bits/stdc++.h>
using namespace std;   
const int INF = 987654321;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

int T, E, V, visited[1001];
vector<int> graph[1001];

void DFS(int x){
    for(int next : graph[x]){
        if(visited[next]) continue;
        visited[next] = 1;
        DFS(next);
    }
    return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    while(T--){
        for(int i = 0; i < 1001; i++) graph[i].clear();
        fill(visited, visited + 1001, 0);

        cin >> E; cin >> V;
        for(int i = 0; i < V; i++){
            int a, b; cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int cnt = 0;
        for(int i = 1; i <= E; i++){
            if(!visited[i]){
                visited[i] = 1;
                DFS(i);
                cnt++;
            }
        }
        if(cnt == 1 && E - 1 == V) cout << "tree\n";
        else cout << "graph\n";
    }
    return 0;
}