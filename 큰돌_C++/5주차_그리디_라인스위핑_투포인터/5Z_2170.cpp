#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};

pair<int, int> L[1000004];
int n, from, to, l, r, ret; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    cin >> n; 
    for(int i = 0; i < n; i++){ 
        cin >> from >> to;
        L[i] = {from, to};
    }
    sort(L, L + n); 
    l = L[0].first; r = L[0].second; 
    for(int i = 1; i < n; i++){ 
        if(r < L[i].first){ 
            ret += (r - l); 
            l = L[i].first;
            r = L[i].second;
        }else if(L[i].first <= r && L[i].second >= r){ 
            r = L[i].second;
        }
    }
    ret += r - l;
    cout << ret << '\n';
}