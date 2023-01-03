#include <bits/stdc++.h>
using namespace std;

int N, d, ret, root;
vector<int> v[51];

int DFS(int x){
    int ret = 0;
    int child = 0;
    for(int i : v[x]){
        if(i == d) continue;
        ret += DFS(i);
        child++;
    }
    if(child == 0) return 1;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        if(a == -1) root = i;
        else v[a].push_back(i);
    }
    cin >> d;
    if(d == root){
        cout << 0 << "\n";
        return 0;
    }
    cout << DFS(root) << "\n";
    return 0;
}