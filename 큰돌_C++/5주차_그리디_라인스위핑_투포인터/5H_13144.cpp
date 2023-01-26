#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

long long s, e, N, cnt[100001], arr[100001];
long long ret;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];

    while(e < N){
        if(!cnt[arr[e]]){
            cnt[arr[e]]++;
            e++;
        } else{
            ret += (e - s);
            cnt[arr[s]]--;
            s++;
        }
    }
    ret += (e - s) * (e - s + 1) / 2;
    cout << ret << "\n";

    return 0;
}
