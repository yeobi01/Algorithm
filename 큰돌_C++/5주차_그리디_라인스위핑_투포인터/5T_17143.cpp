#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;

struct shark{
    int r, c, s, d, z;
    bool live = true;
};

int R, C, M;
int arr[101][101];
vector<shark> v;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> M;
    for(int i = 0; i < M; i++){
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        v.push_back({r, c, s, d, z});
        arr[r][c] = i;
    }

    for(int i = 1; i <= C; i++){
        
    }

    return 0;
}