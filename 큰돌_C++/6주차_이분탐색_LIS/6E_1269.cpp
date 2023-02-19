#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 987654321;

int N, M, ret, temp;
map<int, int> _map;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> temp; _map[temp]++;
    }
    for(int i = 0; i < M; i++){
        cin >> temp; _map[temp]++;
    }
    for(auto x : _map){
        if(x.second == 1) ret++;
    }
    cout << ret << "\n";
    return 0;
}