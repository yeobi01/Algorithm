#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;
vector<int> up, down;
int ans_up[1001], ans_down[1001];
int ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        v.push_back(a);
    }
    for(int i = 0; i < N; i++){
        int temp = v[i];
        int lower_idx = lower_bound(up.begin(), up.end(), temp) - up.begin();
        if(lower_idx == up.size()) up.push_back(temp);
        else up[lower_idx] = temp;
        ans_up[i] = up.size();
    }
    for(int i = N - 1; i >= 0; i--){
        int temp = v[i];
        int lower_idx = lower_bound(down.begin(), down.end(), temp) - down.begin();
        if(lower_idx == down.size()) down.push_back(temp);
        else down[lower_idx] = temp;
        ans_down[i] = down.size();
    }
    for(int i = 0; i < N; i++){
        ans = max(ans, ans_up[i] + ans_down[i] - 1);
    }
    cout << ans << "\n";

    return 0;
}
