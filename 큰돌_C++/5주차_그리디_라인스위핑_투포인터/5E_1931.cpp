#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int N;
vector<pair<int, int>> v;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second < b.second) return true;
    else if(a.second == b.second) return a.first < b.first;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), cmp);
    int cnt = 1;
    int temp = v[0].second;
    for(int i = 1; i < N; i++){
        if(temp <= v[i].first){
            temp = v[i].second;
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
