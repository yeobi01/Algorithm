#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MAX = 1501;

int k, visited[10];
char arr[10];
vector<int> v;
vector<vector<int>> ret;

void DFS(int x, int n){
    if(v.size() == k + 1){
        /*
        for(int ret : v){
            cout << ret;
        }
        cout << "\n";
        */
        ret.push_back(v);
        return;
    }

    if(arr[x] == '<'){
        for(int i = n + 1; i <= 9; i++){
            if(!visited[i]){
                v.push_back(i); visited[i] = 1;
                DFS(x + 1, i);
                v.pop_back(); visited[i] = 0;
            }
        }
    } else if(arr[x] == '>'){
        for(int i = n - 1; i >= 0; i--){
            if(!visited[i]){
                v.push_back(i); visited[i] = 1;
                DFS(x + 1, i);
                v.pop_back(); visited[i] = 0;
            }
        }
    }
    return;
}

bool cmp(vector<int> a, vector<int> b){
    for(int i = 0; i < k; i++){
        if(a[i] < b[i]) return true;
        else if(a[i] > b[i]) return false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> arr[i];
    }
    
    for(int i = 0; i <= 9; i++){
        v.push_back(i); visited[i] = 1;
        DFS(0, i);
        v.pop_back(); visited[i] = 0;
    }

    sort(ret.begin(), ret.end(), cmp);

    for(int x : ret.back()){
        cout << x;
    }
    cout << "\n";
    for(int x : ret.front()){
        cout << x;
    }

    return 0;
}