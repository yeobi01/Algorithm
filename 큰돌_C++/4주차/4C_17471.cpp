#include<bits/stdc++.h>
using namespace std;   
const int INF = 987654321;

int N, people[11], comp[11], visited[11], start1, start2, ret = INF;
vector<int> graph[11];

pair<int, int> DFS(int here, int value){
    visited[here] = 1;
    pair<int, int> ret = {1, people[here]};
    for(int there : graph[here]){
        if(comp[there] != value) continue;
        if(visited[there]) continue;
        pair<int, int> _temp = DFS(there, value);
        ret.first += _temp.first;
        ret.second += _temp.second;
    }
    return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; i++) cin >> people[i];
    for(int i = 1; i <= N; i++){
        int t; cin >> t;
        for(int j = 0; j < t; j++){
            int temp; cin >> temp;
            graph[i].push_back(temp);
        }
    }
    for(int i = 1; i < (1 << N) - 1; i++){
        fill(comp, comp + 11, 0);
        fill(visited, visited + 11, 0);
        for(int j = 0; j < N; j++){
            if(i & (1 << j)) { comp[j + 1] = 1; start1 = j + 1; }
            else start2 = j + 1;
        }
        pair<int, int> p1 = DFS(start1, 1);
        pair<int, int> p2 = DFS(start2, 0);
        if(p1.first + p2.first == N) ret = min(ret, abs(p1.second - p2.second));
    }
    cout << (ret == INF ? -1 : ret) << "\n";
    return 0;
}