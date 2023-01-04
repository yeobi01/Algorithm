#include <bits/stdc++.h>
using namespace std;

int N, M, a[51][51], ret = 987654321, visited[15];
vector<pair<int,int>> ck, house;
vector<int> v;

void go_sum(){
    int temp = 0;
    for(int i = 0; i < house.size(); i++){
        int temp2 = 987654321;
        for(int j = 0; j < M; j++){
            int temp3 = abs(ck[v[j]].first - house[i].first) + abs(ck[v[j]].second - house[i].second);
            temp2 = min(temp2, temp3);
        }
        temp += temp2;
    }
    ret = min(temp, ret);
    return;
}

void go(int start){
    if(v.size() == M){
        go_sum();
        return;
    }
    for(int i = start; i < ck.size(); i++){
        v.push_back(i);
        go(i + 1);
        v.pop_back();
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> a[i][j];
            if(a[i][j] == 1) house.push_back({i, j});
            else if(a[i][j] == 2) ck.push_back({i, j});
        }
    }
    
    go(0);
    cout << ret << "\n";
    
    return 0;
}