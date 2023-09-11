#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;
ll arr[5001];
ll ans[5001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                ans[i] += ans[j];
                ans[i] %= 998244353;
            }
        }
        ans[i]++;
        ans[i] %= 998244353;
    }
    for(int i = 0; i < N; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
