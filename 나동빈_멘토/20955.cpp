#include<bits/stdc++.h>
using namespace std;   
typedef long long ll;
const int INF = 987654321;

int N, M, visited[100001], cnt;
vector<int> v[100001];

void dfs(int x){
    visited[x] = true;
    for(int temp : v[x]){
        if(!visited[temp]) dfs(temp);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }
    cout << M + 2 * cnt - N - 1 << "\n";
    return 0;
}