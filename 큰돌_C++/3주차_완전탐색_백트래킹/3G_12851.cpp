#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MAX = 200000;

int N, K, visited[MAX];
long long cnt[MAX];
queue<int> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    
    visited[N] = 1;
    cnt[N] = 1;

    q.push(N);
    while(!q.empty()){
        int now = q.front(); q.pop();
        for(int next : {now-1, now+1, now*2}){
            if(0 <= next && next < MAX){ // 배열 범위 넘어감..
                if(!visited[next]){
                    q.push(next);
                    visited[next] = visited[now] + 1;
                    cnt[next] += cnt[now];
                } else if(visited[next] == visited[now] + 1){
                    cnt[next] += cnt[now];
                }
            }
        }
    }
    cout << visited[K] - 1 << "\n";
    cout << cnt[K] << "\n";

    return 0;
}