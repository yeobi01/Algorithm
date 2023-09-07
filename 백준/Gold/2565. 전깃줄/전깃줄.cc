#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int,int>> v;
vector<int> ans_v;

int main() {
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
        int temp = v[i].second;
        int lower_idx = lower_bound(ans_v.begin(), ans_v.end(), temp) - ans_v.begin();
        if(lower_idx == ans_v.size()) ans_v.push_back(temp);
        else ans_v[lower_idx] = temp;
    }
    cout << N - ans_v.size() << "\n";

    return 0;
}
