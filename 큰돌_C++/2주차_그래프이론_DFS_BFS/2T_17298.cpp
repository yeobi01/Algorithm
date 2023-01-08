#include <bits/stdc++.h>
using namespace std;

int N, dp[1000001], a[1000001];
stack<int> stk;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, -1, sizeof(dp));
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        while(stk.size() && (a[stk.top()] < a[i])){
            dp[stk.top()] = a[i]; stk.pop();
        }
        stk.push(i);
    }

    for(int i = 0; i < N; i++){
        cout << dp[i] << " ";
    }
    return 0;
}