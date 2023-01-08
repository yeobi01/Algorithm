#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int N, ret = INF;
int least[4], arr[16][5], visited[16];
vector<int> v;

bool check(){
    int sum[5] = {0, };
    for(int i = 0; i < N; i++){
        if(visited[i]){
            sum[0] += arr[i][0];
            sum[1] += arr[i][1];
            sum[2] += arr[i][2];
            sum[3] += arr[i][3];
            sum[4] += arr[i][4];
        }
    }

    for(int i = 0; i < 4; i++){
        if(sum[i] < least[i]) return false;
    }

    if(ret > sum[4]){
        ret = sum[4];
        v.clear();
        for(int i = 0; i < N; i++){ if(visited[i]){ v.push_back(i); } }
    }
    return true;
}

void go(int now){
    if(check()) return;
    
    for(int i = now + 1; i < N; i++){
        if(visited[i]) continue;
        visited[i] = 1;
        go(i);
        visited[i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> least[0] >> least[1] >> least[2] >> least[3]; 
    for(int i = 0; i < N; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3] >> arr[i][4];
    }

    for(int i = 0; i < N; i++){
        visited[i] = 1;
        go(i);
        visited[i] = 0;
    }

    cout << (ret != INF ? ret : -1) << "\n";
    for(int b : v) cout << (b + 1) << " ";

    return 0;
}