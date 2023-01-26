#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int N, s, e, arr[100001], x, ret;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    cin >> x;
    sort(arr, arr + N);

    e = N - 1;
    while(s < e){
        int temp = arr[s] + arr[e];
        if(temp > x) e--;
        else if(temp < x) s++;
        else{ ret++; s++; e--; }
    }

    cout << ret << "\n";
    return 0;
}
