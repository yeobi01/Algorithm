#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 987654321;

int N, M, arr[100001];
int low, high, ret = INF;

bool check(int mid){
    for(int i = 0; i < N; i++){
        if(arr[i] > mid) return false;
    }

    int sum = 0, cnt = 0;
    for(int i = 0; i < N; i++){
        if(sum + arr[i] > mid){
            sum = 0;
            cnt++;
        }
        sum += arr[i];
    } if(sum) cnt++;

    return cnt <= M;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        high += arr[i];
    }
 
    while(low <= high){
        int mid = (low + high) / 2;
        if(check(mid)){
            ret = min(mid, ret);
            high = mid - 1;
        } else{
            low = mid + 1;
        }
    }
    cout << ret << "\n";
    return 0;
}