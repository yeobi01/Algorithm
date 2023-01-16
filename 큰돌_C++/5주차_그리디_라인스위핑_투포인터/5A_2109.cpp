#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int N, p, d, ret;
vector<pair<int,int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> p >> d;
        v.push_back({d, p});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < N; i++){
        pq.push(v[i].second);
        if(pq.size() > v[i].first){
            pq.pop();
        }
    }
    while(pq.size()){
        ret += pq.top(); pq.pop();
    }
    cout << ret << "\n";
    return 0;
}