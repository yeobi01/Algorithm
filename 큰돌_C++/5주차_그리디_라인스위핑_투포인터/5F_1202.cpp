#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

long long N, K, ret;
vector<pair<int, int>> v;
vector<int> bag;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for(int i = 0; i < N; i++){
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    for(int i = 0; i < K; i++){
        int a; cin >> a;
        bag.push_back({a});
    }
    sort(v.begin(), v.end());
    sort(bag.begin(), bag.end());
    priority_queue<long long> pq;

    int j = 0;
    for(int i = 0; i < K; i++){
        while(j < N && v[j].first <= bag[i]){
            pq.push(v[j].second);
            j++;
        }
        if(!pq.empty()){
            ret += pq.top(); pq.pop();
        }
    }
    cout << ret << "\n";
    return 0;
}
