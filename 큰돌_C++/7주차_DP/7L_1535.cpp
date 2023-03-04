#include <bits/stdc++.h>
using namespace std;

int N, L[21], J[21], dp[101];
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> L[i];
    for(int i = 0; i < N; i++) cin >> J[i];

    for(int i = 0; i < N; i++){
        for(int j = 100; j > L[i]; j--){
            dp[j] = max(dp[j], dp[j - L[i]] + J[i]);
        }
    }

    cout << dp[100] << "\n";

    return 0;
}