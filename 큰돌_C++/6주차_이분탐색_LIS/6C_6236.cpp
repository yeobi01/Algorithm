#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 987654321;

int N, M, arr[100001];

bool check(int mid){
    int cnt = 1;
    int real_mid = mid;
    for(int i = 0; i < N; i++){
        if(mid - arr[i] >= 0){
            mid -= arr[i];
        } else{
            mid = real_mid;
            cnt++;
            if(arr[i] > mid) return false;
            else mid -= arr[i];
        }
    }
    return cnt <= M;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    ll low = 1, high = 1000000004, ret;
    while(low <= high){
        int mid = (low + high) / 2;
        if(check(mid)){
            high = mid - 1;
            ret = mid;
        } else low = mid + 1;
    }
    cout << ret << "\n";
    return 0;
}