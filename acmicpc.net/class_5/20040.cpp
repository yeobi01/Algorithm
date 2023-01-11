#include<bits/stdc++.h>
using namespace std;   
const int INF = 987654321;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

int n, m, parent[1000001];

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y){
    x = find(x);
    y = find(y);

    if(x != y){
        if(x >= y) parent[x] = y;
        else parent[y] = x;
    }
}

bool Parent(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b) return false;
    return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) parent[i] = i;

    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        if(Parent(a, b)){
            cout << i + 1;
            return 0;
        }
        merge(a, b);
    }
    cout << "0\n";
    return 0;
}