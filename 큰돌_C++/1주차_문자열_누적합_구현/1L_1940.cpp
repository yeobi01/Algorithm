#include <bits/stdc++.h>
using namespace std;

int N, M, arr[15001], ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int head = 0, tail = N - 1;
    while(head < tail){
        if(arr[head] + arr[tail] == M){
            ans++;
            head++;
        } else if(arr[head] + arr[tail] > M){
            tail--;
        } else{
            head++;
        }
    }
    cout << ans << "\n";

    return 0;
}