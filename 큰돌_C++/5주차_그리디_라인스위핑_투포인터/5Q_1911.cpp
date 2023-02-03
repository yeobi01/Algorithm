#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int N, L, ret;
vector<pair<int, int>> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;
    for(int i = 0; i < N; i++){
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    int idx = 0, cnt;
    for(int i = 0; i < N; i++){
        if(v[i].second <= idx) continue;
        if(idx < v[i].first){
            cnt = (v[i].second - v[i].first) / L + ((v[i].second - v[i].first) % L ? 1 : 0);
            idx = v[i].first + cnt * L;
        } else{
            cnt = (v[i].second - idx) / L + ((v[i].second - idx) % L ? 1 : 0);
            idx = idx + cnt * L;
        }
        ret += cnt;
    }
    cout << ret << "\n";
    return 0;
}