#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 987654321;

int N, len;
vector<int> lis;
vector<pair<int, int>> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < N; i++){
        int lowerIdx = lower_bound(lis.begin(), lis.end(), v[i].second) - lis.begin();
        if(lowerIdx == lis.size()) lis.push_back(v[i].second);
        else lis[lowerIdx] = v[i].second;
    }
    cout << N - lis.size() << "\n";
    return 0;
}