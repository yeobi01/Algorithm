#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;

ll N, M, arr[1000001], sum, _max, ret;

bool check(int mid){
    ll cnt = 0;
    for(int i = 0; i < N; i++){
        cnt += arr[i] / mid;
    }
    return cnt >= M;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        sum += arr[i];
        _max = max(_max, arr[i]);
    }

    ll low = 1, high = _max, mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(check(mid)){
            ret = mid;
            low = mid + 1;
        } else{
            high = mid - 1;
        }
    }
    cout << sum - ret * M << "\n";
    return 0;
}