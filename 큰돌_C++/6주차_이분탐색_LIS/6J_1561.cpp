#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 60000000004;

ll N, M, a[10004], ret, temp;

bool check(ll mid){
    temp = M;
    for(ll i = 0; i < M; i++) temp += mid / a[i];
    return temp >= N;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(ll i = 0; i < M; i++) cin >> a[i];
    if(N <= M){
        cout << N; return 0;
    }

    ll low, high = INF, mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(check(mid)){
            ret = mid;
            high = mid - 1;
        } else low = mid + 1;
    }

    temp = M;
    for(ll i = 0; i < M; i++) temp += ((ret - 1) / a[i]);

    for(ll i = 0; i < M; i++){
        if(ret % a[i] == 0) temp++;
        if(temp == N){
            cout << i + 1 << "\n";
            return 0;
        }
    }
    return 0;
}