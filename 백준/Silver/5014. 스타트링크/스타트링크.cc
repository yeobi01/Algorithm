// 5014번. 스타트링크

#include <bits/stdc++.h>
using namespace std;

int F, S, G, U, D;
int cnt;
bool visited[1000001];
queue<pair<int, int>> q; 

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> F >> S >> G >> U >> D;
    q.push({cnt, S});
    visited[S] = true;
    while(!q.empty()){
        pair<int, int> temp = q.front(); q.pop();
        int cur_cnt = temp.first;
        int cur_floor = temp.second;
        if(cur_floor == G){
            cout << cur_cnt << "\n";
            return 0;
        }
        if((cur_floor + U) <= F && !visited[cur_floor + U]){
            q.push({cur_cnt + 1, cur_floor + U});
            visited[cur_floor + U] = true;
        }
        if((cur_floor - D) > 0 && !visited[cur_floor - D]){
            q.push({cur_cnt + 1, cur_floor - D});
            visited[cur_floor - D] = true;
        }
    }

    cout << "use the stairs\n";
    return 0;
}