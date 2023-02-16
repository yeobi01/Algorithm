#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

long long N, M, a[300004], ret = INF;

bool check(long long mid){
    long long num = 0;
    for(int i = 0; i < M; i++){
        num += a[i] / mid;
        if(a[i] % mid) num++;
    }
    return N >= num;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    long long low = 1, high = 0, mid;
    for(int i = 0; i < M; i++) cin >> a[i], high = max(high, a[i]);
    while(low <= high){
        mid = (low + high) / 2;
        if(check(mid)){
            ret = min(ret, mid);
            high = mid - 1;
        } else low = mid + 1;
    }
    cout << ret << "\n";
    return 0;
}