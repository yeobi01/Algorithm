#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};

pair<int, int> L[1000004];
int N, ret; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N; 
    for(int i = 0; i < N; i++){ 
        int a, b; cin >> a >> b;
        L[i] = {a, b};
    }
    sort(L, L + N); 
    
    int l = L[0].first; 
    int r = L[0].second; 
    for(int i = 1; i < N; i++){ 
        if(r < L[i].first){ 
            ret += (r - l); 
            l = L[i].first;
            r = L[i].second;
        }else if(L[i].first <= r && L[i].second >= r){ 
            r = L[i].second;
        }
    }
    ret += r - l;

    cout << ret << "\n";
    return 0;
}